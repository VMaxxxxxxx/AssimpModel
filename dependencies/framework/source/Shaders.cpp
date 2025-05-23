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

// 加载着色器源码
void Shader::addSourceFromFile(const string &filename)
{
  string shaderCode = common::loadASCIITextFile(filename);
  _sources.push_back(shaderCode);
}

void Shader::compile(GLenum shaderType)
{
    vector<const char *> transformedSources;
    
    // 将string转换成const char*
    transform(
        _sources.begin(),
        _sources.end(),
        back_inserter(transformedSources),
        common::transformStringToCStr
    );

    // 创建shader对象
    GLuint shader = glCreateShader(shaderType);

    // 设置源码
    glShaderSource(
        shader,
        transformedSources.size(),
        transformedSources.data(),
        nullptr
    ); 

    // 编译
    glCompileShader(shader);

    // 检查是否成功
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

// 将一个已经编译好的shader附加到程序对象上
void ShaderProgram::attach(Shader *shader) {
  glAttachShader(_program, shader->getId());
}

// 将所有附加的着色器链接成可用的程序
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

// 使用当前程序进行渲染
void ShaderProgram::use()
{
    glUseProgram(_program);
}
