#include "pipeline.hpp"

#include <fstream>
#include <stdexcept>

namespace spark {

    Pipeline::Pipeline(SparkDevice &device, const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo) : sparkDevice{device} {
        createGraphicsPipeline(vert, frag, configInfo);
    }

    std::vector<char> Pipeline::readFile(const std::string& filepath) {

        std::ifstream file(filepath, std::ios::ate | std::ios::binary);

        if(!file.is_open()) {
            throw std::runtime_error("Failed to open file!: " + filepath);
        }

        size_t size = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(size);

        file.seekg(0);
        file.read(buffer.data(), size);

        file.close();
        return buffer;

    }

    void Pipeline::createGraphicsPipeline(const std::string& vert, const std::string& frag, const PipelineConfigInfo& configInfo) {

        auto vertCode = readFile(vert);
        auto fragCode = readFile(frag);

    }

    void createShaderModule(const std::vector<char> &code, VkShaderModule* shaderModule) {

        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if(vkCreateShaderModule(sparkDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create shader module!");
        }

    }

    PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};

        return configInfo;
    }

}