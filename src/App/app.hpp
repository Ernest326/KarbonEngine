#pragma once

#include "window.hpp"

namespace spark {

class App {

public:
    static constexpr int WIDTH=800;
    static constexpr int HEIGHT=800;

    void run();

private:
    Window window{WIDTH, HEIGHT, "Spark!"};

};

}