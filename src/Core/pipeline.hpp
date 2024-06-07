#pragma once

//Engine includes
#include "karbon_device.hpp"
#include "vertex_model.hpp"

//std includes
#include <string>
#include <vector>

namespace karbon {

struct PipelineConfigInfo {
    PipelineConfigInfo(const PipelineConfigInfo&) = delete;
    PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

    //No longer needed since we are now using a dynamic viewport
    //VkViewport viewport;
    //VkRect2D scissor;
    VkPipelineViewportStateCreateInfo viewportInfo;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    std::vector<VkDynamicState> dynamicStateEnables;
    VkPipelineDynamicStateCreateInfo dynamicStateInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

class Pipeline {

public:
    Pipeline(KarbonDevice& device, const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo);
    Pipeline() = default;
    ~Pipeline();

    Pipeline(const Pipeline&) = delete;
    Pipeline& operator=(const Pipeline&) = delete;

    void bind(VkCommandBuffer commandBuffer);
    static PipelineConfigInfo defaultPipelineConfigInfo(PipelineConfigInfo& configInfo);
    
private:
    static std::vector<char> readFile(const std::string& filePath);

    void createGraphicsPipeline(const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo);
    void createShaderModule(const std::vector<char> &code, VkShaderModule* shaderModule);

    KarbonDevice& karbonDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

};
}