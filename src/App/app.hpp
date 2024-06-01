#pragma once

#include "../Core/karbon_device.hpp"
#include "../Core/pipeline.hpp"
#include "../Core/swapchain.hpp"
#include "window.hpp"

#include <memory>
#include <vector>

namespace karbon {

class App {

public:
    static constexpr int WIDTH=800;
    static constexpr int HEIGHT=800;

    App();
    ~App();

    App(const App&) = delete;
    void operator=(const App&) = delete;

    void run();

private:
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    Window window{WIDTH, HEIGHT, "Spark!"};
    KarbonDevice karbonDevice{window};
    KarbonSwapChain karbonSwapChain { karbonDevice, window.getExtent() };
    std::unique_ptr<Pipeline> karbonPipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;

};

}