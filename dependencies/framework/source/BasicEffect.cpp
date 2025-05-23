#include "BasicEffect.hpp"
#include "Shaders.hpp"
#include "Config.hpp"

#include <memory>

namespace fw
{

BasicEffect::BasicEffect()
{
}

BasicEffect::~BasicEffect()
{
}

void BasicEffect::create()
{
    createShaders();
}

void BasicEffect::destroy()
{
}

void BasicEffect::begin()
{
    _shaderProgram->use();
}

void BasicEffect::end()
{
}

void BasicEffect::createShaders()
{
    // 创建顶点着色器
    std::shared_ptr<Shader> vs = std::make_shared<Shader>();
    // 加载顶点shader源码
    vs->addSourceFromFile(RESOURCE("shaders/MVPTransformTexCoord.vert"));
    // 编译成GL的顶点shader
    vs->compile(GL_VERTEX_SHADER);

    // 创建片段着色器
    std::shared_ptr<Shader> fs = std::make_shared<Shader>();
    // 记载源码
    fs->addSourceFromFile(RESOURCE("shaders/SolidColor.frag"));
    fs->compile(GL_FRAGMENT_SHADER);

    // 创建shader程序对象
    _shaderProgram = std::make_shared<ShaderProgram>();
    _shaderProgram->attach(vs.get());   // 附加顶点着色器
    _shaderProgram->attach(fs.get());   // 附加片段着色器
    _shaderProgram->link();             // 链接成一个完整的shader程序
}

}
