#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include <learnopengl/shader_m.h>
#include <learnopengl/model.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // ���� glm::translate, glm::scale

// ��Ⱦ����ģ�ͣ�ë���͵���
// shader: ʹ�õ���ɫ������
// cubeModel: ë��ģ�Ͷ���
// toolModel: ����ģ�Ͷ���
// cubePosition: ë��ģ������������ϵ�е�λ��
// toolBasePosition: ����ģ�͵Ļ����������� (XZ�̶�, YΪ��������)
// time: ��ǰʱ�䣬���ڵ��ߵĶ���
void renderModels(Shader& shader, Model& cubeModel, Model& toolModel,
    const glm::vec3& cubePosition,
    const glm::vec3& toolBasePosition,
    float time);

#endif // MODEL_RENDERER_H 