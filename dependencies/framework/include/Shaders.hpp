#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <glad/glad.h>

#include <string>
#include <vector>

// ����OpenGL��ɫ���ķ�װ
class Shader
{
public:
  Shader();
  Shader(const Shader &shader) = default;
  virtual ~Shader();

  inline GLenum getType() { return _shaderType; }
  inline GLuint getId() { return _shaderId; }

  // �����ļ�����Ϊ�ַ�������ӵ�_sources�У�Ȼ�����
  void addSourceFromFile(const std::string &filename);
  void compile(GLenum shaderType);

private:
  std::vector<std::string> _sources;	// ���GLSLԴ���ַ���
  GLenum _shaderType;	// ��ɫ������
  GLuint _shaderId;		// ��ɫ�������ID
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
