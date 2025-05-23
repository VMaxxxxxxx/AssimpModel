#include "ParametricSurfaceIntersection.hpp"

namespace fw
{

ParametricSurfaceIntersection::ParametricSurfaceIntersection():
    lhsParameters{},
    rhsParameters{},
    scenePosition{}
{
}
// 两个曲面的参数坐标、交点世界坐标
ParametricSurfaceIntersection::ParametricSurfaceIntersection(
    glm::dvec2 lhsParameters,
    glm::dvec2 rhsParameters,
    glm::dvec3 scenePosition
):
    lhsParameters{lhsParameters},
    rhsParameters{rhsParameters},
    scenePosition{scenePosition}
{
}

}
