#include "app.hpp"
#include <stdexcept>
#include <array>

namespace karbon {

App::App() {
    loadModels();
    createPipelineLayout();
    recreateSwapChain();
    createCommandBuffers();
}

App::~App() {
    vkDestroyPipelineLayout(karbonDevice.device(), pipelineLayout, nullptr);
}

//Main loop for the entire thing! :D
void App::run() {

    while(!window.shouldClose()) {
        glfwPollEvents();
        drawFrame();
    }

    vkDeviceWaitIdle(karbonDevice.device()); //Wait for all GPU operations to complete

}

void App::createPipelineLayout() {

    VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 0;
    pipelineLayoutInfo.pSetLayouts = nullptr;
    pipelineLayoutInfo.pushConstantRangeCount = 0;
    pipelineLayoutInfo.pPushConstantRanges = nullptr;

    if(vkCreatePipelineLayout(karbonDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Pipeline Layout!");
    }
}

void App::loadModels() {
    std::vector<VertexModel::Vertex> vertices {
        {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
    };

    vertexModel = std::make_unique<VertexModel>(karbonDevice, vertices);
}

void App::createPipeline() {

    assert(karbonSwapChain != nullptr && "Cannot create pipeline before swapchain");
    assert(pipelineLayout != nullptr && "Cannot create pipeline before pipeline layout");

    PipelineConfigInfo pipelineConfig{};
    auto pipelineConfig = Pipeline::defaultPipelineConfigInfo(pipelineConfig);

    pipelineConfig.renderPass = karbonSwapChain->getRenderPass();
    pipelineConfig.pipelineLayout = pipelineLayout;
    karbonPipeline = std::make_unique<Pipeline>(
        karbonDevice,
        "../shaders/test_shader.vert.spv",
        "../shaders/test_shader.frag.spv",
        pipelineConfig
    );

}

void App::recreateSwapChain() {
    auto extent = window.getExtent();

    //The program will pause and wait while one of the dimensions are sizeless
    while (extent.width == 0 || extent.height == 0) {
        extent = window.getExtent();
        glfwWaitEvents();
    }

    vkDeviceWaitIdle(karbonDevice.device());

    if(karbonSwapChain == nullptr) {
        karbonSwapChain = std::make_unique<KarbonSwapChain>(karbonDevice, extent);
    } else {
        karbonSwapChain = std::make_unique<KarbonSwapChain>(karbonDevice, extent, std::move(karbonSwapChain));
        if(karbonSwapChain->imageCount() != commandBuffers.size()) {
            freeCommandBuffers();
            createCommandBuffers();
        }
    }

    createPipeline();
}

void App::createCommandBuffers() {

    commandBuffers.resize(karbonSwapChain->imageCount());

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = karbonDevice.getCommandPool();
    allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

    if(vkAllocateCommandBuffers(karbonDevice.device(), &allocInfo, commandBuffers.data())!=VK_SUCCESS) {
        std::runtime_error("Failed to allocate command buffer!");
    }

}

void App::freeCommandBuffers() {
    vkFreeCommandBuffers(
        karbonDevice.device(), 
        karbonDevice.getCommandPool(), 
        static_cast<uint32_t>(commandBuffers.size()), 
        commandBuffers.data());
    commandBuffers.clear();
}

void App::recordCommandBuffer(int imageIndex) {
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if(vkBeginCommandBuffer(commandBuffers[imageIndex], &beginInfo) != VK_SUCCESS) {
        throw std::runtime_error("Failed to begin recording command buffer!");
    }

    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = karbonSwapChain->getRenderPass();
    renderPassInfo.framebuffer = karbonSwapChain->getFrameBuffer(imageIndex);

    renderPassInfo.renderArea.offset = {0,0};
    renderPassInfo.renderArea.extent = karbonSwapChain->getSwapChainExtent();

    std::array<VkClearValue, 2> clearValues{};
    clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f}; //Index 0 is color attachment
    clearValues[1].depthStencil = {1.0f, 0}; //Index 1 is depth attachment
    renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
    renderPassInfo.pClearValues = clearValues.data();

    vkCmdBeginRenderPass(commandBuffers[imageIndex], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = static_cast<float>(karbonSwapChain->getSwapChainExtent().width);
    viewport.height = static_cast<float>(karbonSwapChain->getSwapChainExtent().height);
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    
    VkRect2D scissor{{0, 0}, karbonSwapChain->getSwapChainExtent()};
    vkCmdSetViewport(commandBuffers[imageIndex], 0, 1, &viewport);
    vkCmdSetScissor(commandBuffers[imageIndex], 0, 1, &scissor);

    karbonPipeline->bind(commandBuffers[imageIndex]);
    vertexModel->bind(commandBuffers[imageIndex]);
    vertexModel->draw(commandBuffers[imageIndex]);

    vkCmdEndRenderPass(commandBuffers[imageIndex]);

    if(vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS) {
        throw std::runtime_error("Failed to record command buffer!");
    }
    
}

void App::drawFrame() {
    uint32_t imageIndex;
    auto result = karbonSwapChain->acquireNextImage(&imageIndex);

    //Check if the surface is no longer compatible with the swapchain(happens after resize)
    if(result == VK_ERROR_OUT_OF_DATE_KHR) {
        recreateSwapChain();
        return;
    }

    if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        throw std::runtime_error("Failed to acquire swap chain image!");
    }

    recordCommandBuffer(imageIndex);
    result = karbonSwapChain->submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);

    if(result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || window.wasWindowsResized()) {
        window.resetWindowResized();
        recreateSwapChain();
        return;
    }
    if (result != VK_SUCCESS) {
        throw std::runtime_error("Failed to present swap chain image!");
    }

}

}