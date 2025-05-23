#pragma once
#include <glm/glm.hpp>

namespace fw
{
    // ��ʾһ������Ľ�����Ϣ
struct ParametricSurfaceIntersection
{
public:
    ParametricSurfaceIntersection();
    ParametricSurfaceIntersection(
        glm::dvec2 lhsParameters,
        glm::dvec2 rhsParameters,
        glm::dvec3 scenePosition
    );

    glm::dvec2 lhsParameters;   // ��һ������ࣩ�����ϵĲ������꣨u�� v��
    glm::dvec2 rhsParameters;   // �ڶ������Ҳࣩ�����ϵĲ������꣨u�� v��
    glm::dvec3 scenePosition;   // �������������ռ��е�3D���꣨x��y��z��
};

}
