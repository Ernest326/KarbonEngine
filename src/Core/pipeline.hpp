#pragma once

#include "spark_device.hpp"
#include <string>
#include <vector>

namespace spark {

struct PipelineConfigInfo {};
class Pipeline {

public:
    Pipeline(SparkDevice& device, const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo);
    ~Pipeline() {}

    Pipeline(const Pipeline&) = delete;
    void operator=(const Pipeline&) = delete;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
    
private:
    static std::vector<char> readFile(const std::string& filePath);

    void createGraphicsPipeline(const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo);
    void createShaderModule(const std::vector<char> &code, VkShaderModule* shaderModule);

    SparkDevice& sparkDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

};
}