#pragma once

#include "IParametricSurfaceUV.hpp"
#include <glm/glm.hpp>

namespace fw
{
    // 最近点粗略查找
class ParametricSurfaceClosestPointNaiveFinder
{
public:
    ParametricSurfaceClosestPointNaiveFinder();
    virtual ~ParametricSurfaceClosestPointNaiveFinder();

    // 指定要寻找最近点的目标点
    void setReferencePoint(glm::dvec3 referencePoint);
    // 设置采样分辨率
    void setSamplingResolution(glm::ivec2 samplingResolution);
    // 寻找最近点的参数
    glm::dvec2 find(const IParametricSurfaceUV& surface);

private:
    glm::dvec3 _referencePoint;
    glm::ivec2 _samplingResolution;
};

}
