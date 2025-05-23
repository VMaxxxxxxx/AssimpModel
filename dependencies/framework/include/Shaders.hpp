#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <glad/glad.h>

#include <string>
#include <vector>

// 单个OpenGL着色器的封装
class Shader
{
public:
  Shader();
  Shader(const Shader &shader) = default;
  virtual ~Shader();

  inline GLenum getType() { return _shaderType; }
  inline GLuint getId() { return _shaderId; }

  // 加载文件内容为字符串，添加到_sources中，然后编译
  void addSourceFromFile(const std::string &filename);
  void compile(GLenum shaderType);

private:
  std::vector<std::string> _sources;	// 多个GLSL源码字符串
  GLenum _shaderType;	// 着色器类型
  GLuint _shaderId;		// 着色器对象的ID
};


class ShaderProgram {
public:
  ShaderProgram();
  ~ShaderProgram();

  void attach(Shader *shader);
  void link();
  void use();

  GLuint getId() { return _program; }

private:
  GLuint _program;
};

#endif
