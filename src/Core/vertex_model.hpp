#pragma once

#include "karbon_device.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE //Opengl uses -1 to 1, Vulkan uses 0 to 1
#include <glm/glm.hpp>

namespace karbon {

class VertexModel {
 public:
    struct Vertex {
        glm::vec2 position;
        glm::vec3 color;
        static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
    };

    VertexModel(KarbonDevice &device, const std::vector<Vertex> &vertices);
    ~VertexModel();

    VertexModel(const VertexModel &) = delete;
    VertexModel &operator=(const VertexModel &) = delete;

    void bind(VkCommandBuffer commandBuffer);
    void draw(VkCommandBuffer commandBuffer);

 private:
    void createVertexBuffers(const std::vector<Vertex> &vertices);

    KarbonDevice &karbonDevice;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    uint32_t vertexCount;

};
}