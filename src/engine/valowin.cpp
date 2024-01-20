#include "valowin.h"

valowin::valowin(int width, int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(width, height, "valogen", nullptr, nullptr);
}

valowin::~valowin()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

GLFWwindow* valowin::getWindowInstance()
{
    return m_window;
}

void valowin::render()
{
    while (!glfwWindowShouldClose(m_window)) {
        processInput(m_window);
        glfwPollEvents();
    }
}

void valowin::processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS ) {
        glfwSetWindowShouldClose(window, true);
    }
}
