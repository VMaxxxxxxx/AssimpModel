#include "TextureUtils.hpp"
#include <stb_image.h>

using namespace std;

// 从给定路径加载一张纹理图，返回一个纹理对象ID
GLuint loadTextureFromFile(const string &filename)
{
    int width, height, components;
    unsigned char *image = stbi_load(
        filename.c_str(), &width, &height, &components, 0
    );  // 加载图像(文件名，输出图像宽高，输出通道数，自动决定事件通道数)

    if (image == nullptr)
    {
        throw string("Cannot load specified texture: " + filename);
    }

    GLenum componentsEnum;
    // 根据通道数，决定合适的格式
    switch (components)
    {
    case 3:
        componentsEnum = GL_RGB;
        break;
    case 4:
        componentsEnum = GL_RGBA;
        break;
    default:
        stbi_image_free(image);
        throw string("Components amount currently not supported.");
    }

    // 创建纹理对象，并绑定
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 设置纹理过滤参数，设置放大和缩小时采样方式为线性插值
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 上传纹理数据到GPU
    glTexImage2D(GL_TEXTURE_2D, 0, componentsEnum, width, height, 0,
        componentsEnum, GL_UNSIGNED_BYTE, image);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(image);

    return texture;
}
