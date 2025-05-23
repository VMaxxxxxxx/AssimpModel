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
    // ����������ɫ��
    std::shared_ptr<Shader> vs = std::make_shared<Shader>();
    // ���ض���shaderԴ��
    vs->addSourceFromFile(RESOURCE("shaders/MVPTransformTexCoord.vert"));
    // �����GL�Ķ���shader
    vs->compile(GL_VERTEX_SHADER);

    // ����Ƭ����ɫ��
    std::shared_ptr<Shader> fs = std::make_shared<Shader>();
    // ����Դ��
    fs->addSourceFromFile(RESOURCE("shaders/SolidColor.frag"));
    fs->compile(GL_FRAGMENT_SHADER);

    // ����shader�������
    _shaderProgram = std::make_shared<ShaderProgram>();
    _shaderProgram->attach(vs.get());   // ���Ӷ�����ɫ��
    _shaderProgram->attach(fs.get());   // ����Ƭ����ɫ��
    _shaderProgram->link();             // ���ӳ�һ��������shader����
}

}
