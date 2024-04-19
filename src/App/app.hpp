#pragma once

#include "../Core/pipeline.hpp"
#include "window.hpp"
#include "../Core/spark_device.hpp"

namespace spark {

class App {

public:
    static constexpr int WIDTH=800;
    static constexpr int HEIGHT=800;

    void run();

private:
    Window window{WIDTH, HEIGHT, "Spark!"};
    SparkDevice device{window};
    Pipeline pipeline {
        device,
        "../../shaders/test_shader.vert.spv",
        "../../shaders/test_shader.frag.spv",
        Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
    };

};

}