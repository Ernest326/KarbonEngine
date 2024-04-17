#include "app.hpp"

namespace spark {

void App::run() {

    while(!window.shouldClose()) {
        glfwPollEvents();
    }

}

}