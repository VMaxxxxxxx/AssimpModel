#pragma once
#include <glm/glm.hpp>

namespace fw
{
    // 表示一个曲面的交点信息
struct ParametricSurfaceIntersection
{
public:
    ParametricSurfaceIntersection();
    ParametricSurfaceIntersection(
        glm::dvec2 lhsParameters,
        glm::dvec2 rhsParameters,
        glm::dvec3 scenePosition
    );

    glm::dvec2 lhsParameters;   // 第一个（左侧）曲面上的参数坐标（u， v）
    glm::dvec2 rhsParameters;   // 第二个（右侧）曲面上的参数坐标（u， v）
    glm::dvec3 scenePosition;   // 这个交点在世界空间中的3D坐标（x，y，z）
};

}
