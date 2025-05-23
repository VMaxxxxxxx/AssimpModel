#pragma once

#include "OpenGLHeaders.hpp"
#include <glm/glm.hpp>

class OpenGLApplication
{
public:
    OpenGLApplication();
    virtual ~OpenGLApplication();

    // 创建并初始化glfw基本环境，
    void create();
    void destroy();
    // 循环检测窗体事件、做更新、做渲染、交换双缓冲区
    void run();

protected:
    // 在回调函数中调用，交由子类对象去重构实现具体的处理逻辑
    virtual void onCreate();
    virtual void onDestroy();
    virtual void onUpdate();
    virtual void onRender();

    virtual void onMouseButton(int button, int action, int mods);
    virtual void onScroll(double xoffset, double yoffset);
    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onChar(unsigned int c);

    // 窗体事件的回调函数
    static void mouseButtonCallback(
        GLFWwindow *window, int button, int action, int mods
    );

    static void scrollCallback(
        GLFWwindow *window, double xoffset, double yoffset
    );

    static void keyCallback(
        GLFWwindow *window, int key, int scancode, int action, int mods
    );

    static void charCallback(GLFWwindow *window, unsigned int c);

    glm::vec2 getMousePosition();

    // 窗体对象
    GLFWwindow *_window;
};
