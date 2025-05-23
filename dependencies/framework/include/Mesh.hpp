#pragma once

#include <glad/glad.h>
#include <vector>

#include <iostream>
using namespace std;

template<typename VertexType>
class Mesh
{
public:
    // 封装顶点数组对象VAO、顶点缓冲对象VBO、索引缓冲对象EBO
    Mesh();
    Mesh(
        const std::vector<VertexType> &vertices,
        const std::vector<GLuint> &indices
    );

    Mesh(Mesh<VertexType> &&mesh);

    ~Mesh();

    void destroy();
    void render() const;

protected:
    GLuint _vao, _vbo, _ebo;
    int _numElements;

    void createBuffers(
        const std::vector<VertexType> &vertices,
        const std::vector<GLuint> &indices
    );

    void destroyBuffers();
};

// 默认构造
template <typename VertexType>
Mesh<VertexType>::Mesh():
    _numElements{0},
    _vao{0},
    _vbo{0},
    _ebo{0}
{
}

// 参数构造
template <typename VertexType>
Mesh<VertexType>::Mesh(
    const std::vector<VertexType> &vertices,
    const std::vector<GLuint> &indices
):
    _numElements{0},
    _vao{0},
    _vbo{0},
    _ebo{0}
{
    createBuffers(vertices, indices);
}

// 移动构造，无拷贝构造
template <typename VertexType>
Mesh<VertexType>::Mesh(Mesh<VertexType> &&mesh) :
    _vao(std::move(mesh._vao)),
    _vbo(std::move(mesh._vbo)),
    _ebo(std::move(mesh._ebo)),
    _numElements(std::move(mesh._numElements))
{
    mesh._vao = mesh._vbo = mesh._ebo = 0;
}

template <typename VertexType>
Mesh<VertexType>::~Mesh()
{
    destroy();
}

template <typename VertexType>
void Mesh<VertexType>::destroy()
{
    destroyBuffers();
}

// 绑定VAO，绘制三角形
template <typename VertexType>
void Mesh<VertexType>::render() const
{
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, _numElements, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

// 缓冲创建逻辑
template <typename VertexType>
void Mesh<VertexType>::createBuffers(
    const std::vector<VertexType> &vertices,
    const std::vector<GLuint> &indices
)
{
    // 创建并绑定VAO、VBO、EBO，上传顶点数据，索引数据
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexType),
        vertices.data(), GL_STATIC_DRAW);   // 顶点数据

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        indices.size() * sizeof(GLuint),
        indices.data(), GL_STATIC_DRAW);    // 索引数据

    VertexType::setupAttribPointers();

    glBindVertexArray(0);

    _numElements = indices.size();
}

template <typename VertexType>
void Mesh<VertexType>::destroyBuffers()
{
    if (_vbo) glDeleteBuffers(1, &_vbo);
    if (_ebo) glDeleteBuffers(1, &_ebo);
    if (_vao) glDeleteVertexArrays(1, &_vao);
    _vao = _vbo = _ebo = 0;
}
