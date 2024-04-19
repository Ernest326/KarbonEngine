#include "app.hpp"

#include <stdexcept>

namespace spark {

App::App() {
    createPipelineLayout();
    createPipeline();
    createCommandBuffers();
}

App::~App() {
    vkDestroyPipelineLayout(sparkDevice.device(), pipelineLayout, nullptr);
}

void App::run() {

    while(!window.shouldClose()) {
        glfwPollEvents();
    }

}

void App::createPipelineLayout() {

    VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 0;
    pipelineLayoutInfo.pSetLayouts = nullptr;
    pipelineLayoutInfo.pushConstantRangeCount = 0;
    pipelineLayoutInfo.pPushConstantRanges = nullptr;

    if(vkCreatePipelineLayout(sparkDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Pipeline Layout!");
    }
}
void App::createPipeline() {

    auto pipelineConfig = Pipeline::defaultPipelineConfigInfo(sparkSwapChain.width(), sparkSwapChain.height());

    pipelineConfig.renderPass = sparkSwapChain.getRenderPass();
    pipelineConfig.pipelineLayout = pipelineLayout;
    pipelineLayout = std::make_unique<Pipeline>(
        sparkDevice,
        "../../shaders/test_shader.vert.spv",
        "../../shaders/test_shader.frag.spv",
        pipelineConfig
    );

}
void App::createCommandBuffers() {

}
void App::drawFrame() {
    
}

}