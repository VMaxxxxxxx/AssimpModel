#include "Shaders.hpp"
#include "Common.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>

using namespace std;

Shader::Shader() : _shaderType(0), _shaderId(0) {
}

Shader::~Shader() {
  if (!_shaderId) {
    glDeleteShader(_shaderId);
    _shaderId = 0;
  }
}

// ������ɫ��Դ��
void Shader::addSourceFromFile(const string &filename)
{
  string shaderCode = common::loadASCIITextFile(filename);
  _sources.push_back(shaderCode);
}

void Shader::compile(GLenum shaderType)
{
    vector<const char *> transformedSources;
    
    // ��stringת����const char*
    transform(
        _sources.begin(),
        _sources.end(),
        back_inserter(transformedSources),
        common::transformStringToCStr
    );

    // ����shader����
    GLuint shader = glCreateShader(shaderType);

    // ����Դ��
    glShaderSource(
        shader,
        transformedSources.size(),
        transformedSources.data(),
        nullptr
    ); 

    // ����
    glCompileShader(shader);

    // ����Ƿ�ɹ�
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "Error: Shader compilation failed" << std::endl 
            << infoLog << std::endl;
        return; // todo: throw exception
    }

    _shaderType = shaderType;
    _shaderId = shader;
}

ShaderProgram::ShaderProgram() {
  _program = glCreateProgram();
}

ShaderProgram::~ShaderProgram() {
  if (_program) {
    glDeleteProgram(_program);
    _program = 0;
  }
}

// ��һ���Ѿ�����õ�shader���ӵ����������
void ShaderProgram::attach(Shader *shader) {
  glAttachShader(_program, shader->getId());
}

// �����и��ӵ���ɫ�����ӳɿ��õĳ���
void ShaderProgram::link() {
  glLinkProgram(_program);

  GLint success;
  GLchar infoLog[512];
  glGetProgramiv(_program, GL_LINK_STATUS, &success);
  if (!success) {
      glGetProgramInfoLog(_program, 512, NULL, infoLog);
      std::cout << "Error: Shader link" << std::endl << infoLog << std::endl;
  }
}

// ʹ�õ�ǰ���������Ⱦ
void ShaderProgram::use()
{
    glUseProgram(_program);
}
