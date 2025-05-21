#include "renderer_setup.h"
#include <iostream> // ���� std::cout

// learnopengl/stb_image.h ��Ҫ������壬���ǽ������.cpp���Ա�����ض���
// ͨ�����������ڰ���stb_image.h���Ǹ�.cpp�ļ��Ķ�����������ȫ�������ļ���
// ������� model_loading.cpp �л��� #include <learnopengl/model.h> �������� stb_image
// ���û�У����� configureGlobalOpenGLState �е����� stbi_ ����������Ҫȷ�� stb_image.h ������
// ������stbi_set_flip_vertically_on_load����model.h�д���ģ����ﲻ��Ҫ��ʽ����stb_image.h����STB_IMAGE_IMPLEMENTATION
// ���ǽ�stbi_set_flip_vertically_on_load�ĵ��÷��� configureGlobalOpenGLState ��

// ����stb_image.h���������Ա����stbi_set_flip_vertically_on_load
// ���ͨ������model.h�д���ģ���Ϊ��ȷ�����������ԣ������������ȷ��
// ���������淶���������õ���stbi_set_flip_vertically_on_load�ĵط�ȷ��stb_image.h�ѱ���ȷ���������á�
// Ϊ�˼��������������������ļ� (model_loading.cpp) ��ͨ�� #include <learnopengl/model.h> ��Ӱ�����
// ���ֱ���ڴ˴�ʹ��stbi����������Ҫ #define STB_IMAGE_IMPLEMENTATION �� #include "stb_image.h"
// ����Ϊ����ֻ��װ glEnable ��δ�����ܵ�����OpenGL״̬��stbi�ĵ����Կɱ�����main���Ƶ�model loading���֡�
// �����ǽ� stbi_set_flip_vertically_on_load(true); ���� configureGlobalOpenGLState()��
// Ҫ����������Ҫ�ܷ��ʵ���������������� learnopengl/model.h �б����õģ���������� stb_image.h��
// ����ζ�� model.h ����������Ӧ�ô���stb_image�İ�����
// ʵ���ϣ�`stbi_set_flip_vertically_on_load` �� stb_image.h �еĺ�����
// `learnopengl/model.h` ���� `#include <stb_image.h>`��
// ͨ����`#define STB_IMAGE_IMPLEMENTATION` �����һ�� cpp �ļ��У��Ա������Ӵ���
// learnopengl �̳��У����ͨ�������� cpp �ļ�����ĳ��ֻ����һ�ε� cpp �ļ���
// ���� `model_loading.cpp` �ǰ��� `STB_IMAGE_IMPLEMENTATION` �ĵط����������û�еĻ���
// ���� `learnopengl/model.h` �ڲ��Ѿ�����
// ��������ֻ����������������������ڱ𴦱���ȷ���ӡ�

// Forward declaration if needed, or include the header that provides it.
// For stbi_set_flip_vertically_on_load:
#include <stb_image.h> 
// ע��: ��������ط�û�� #define STB_IMAGE_IMPLEMENTATION���ڴ˴���������ܻᵼ�¶��ض��塣
// ���ȷ�����ļ���ĳ���ض��� .cpp �ļ���������塣
// ��������ֻ���ع������� learnopengl/model.h �� model_loading.cpp �Ѿ�����������

bool initGLFW(GLFWwindow*& window, const char* title,
    void (*fb_callback)(GLFWwindow*, int, int),
    void (*mouse_callback)(GLFWwindow*, double, double),
    void (*scroll_callback)(GLFWwindow*, double, double),
    unsigned int scr_width, unsigned int scr_height)
{
    // glfw: ��ʼ��������
    // ------------------------------
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw ���ڴ���
    // --------------------
    window = glfwCreateWindow(scr_width, scr_height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, fb_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // ֪ͨGLFW�������ǵ����
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return true;
}

bool initGLAD()
{
    // glad: ��������OpenGL����ָ��
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}

void configureGlobalOpenGLState()
{
    // ����ȫ�� opengl ״̬
    // -----------------------------
    // ���� stb_image.h �ڼ���ģ��ǰ��תy�ᣨ�������꣩
    // �������ͨ���ڼ����κ������ģ��֮ǰ����һ�Ρ�
    stbi_set_flip_vertically_on_load(true);
    glEnable(GL_DEPTH_TEST);
}