#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace karbon {

class Window {

public:
    Window(int w, int h, std::string name);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;
    
    bool shouldClose() { return glfwWindowShouldClose(window); }

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};}
    bool wasWindowsResized() { return windowResized; }
    void resetWindowResized() { windowResized=false; }

private:
    static void windowResizeCallback(GLFWwindow *window, int width, int height);
    void initWindow();

    int width;
    int height;
    bool windowResized = false; //Used to check if window was resized in order to regenerate swapchain

    std::string windowName;
    GLFWwindow *window;

};
}