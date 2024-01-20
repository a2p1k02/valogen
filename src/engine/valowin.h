#ifndef VALOGEN_VALOWIN_H
#define VALOGEN_VALOWIN_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class valowin {
public:
    valowin(int width, int height);
    ~valowin();
    void render();
    GLFWwindow* getWindowInstance();
private:
    GLFWwindow* m_window;

    static void processInput(GLFWwindow* window);
};

#endif //VALOGEN_VALOWIN_H
