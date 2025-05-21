#ifndef RENDERER_SETUP_H
#define RENDERER_SETUP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// ��������
// ��ʼ��GLFW����������
// window: GLFW���ڶ�������ã����ɸú������������
// title: ���ڱ���
// fb_callback: ֡�����С�ı�ʱ�Ļص�����ָ��
// mouse_callback: ����ƶ�ʱ�Ļص�����ָ��
// scroll_callback: �����ֹ���ʱ�Ļص�����ָ��
// scr_width, scr_height: ��Ļ�����ڣ��Ŀ�Ⱥ͸߶�
// ����ֵ: ����ɹ����������򷵻� true�����򷵻� false
bool initGLFW(GLFWwindow*& window, const char* title,
    void (*fb_callback)(GLFWwindow*, int, int),
    void (*mouse_callback)(GLFWwindow*, double, double),
    void (*scroll_callback)(GLFWwindow*, double, double),
    unsigned int scr_width, unsigned int scr_height);

// ��ʼ��GLAD
// ����ֵ: ����ɹ���ʼ��GLAD�򷵻� true�����򷵻� false
bool initGLAD();

// ����ȫ��OpenGL״̬
void configureGlobalOpenGLState();

#endif // RENDERER_SETUP_H 