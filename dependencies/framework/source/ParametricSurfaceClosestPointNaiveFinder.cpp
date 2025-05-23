#include "ParametricSurfaceClosestPointNaiveFinder.hpp"
#include <limits>

namespace fw
{

ParametricSurfaceClosestPointNaiveFinder::
        ParametricSurfaceClosestPointNaiveFinder():
    _referencePoint{},
    _samplingResolution{}
{
}

ParametricSurfaceClosestPointNaiveFinder::
        ~ParametricSurfaceClosestPointNaiveFinder()
{
}

void ParametricSurfaceClosestPointNaiveFinder::
        setReferencePoint(glm::dvec3 referencePoint)
{
    _referencePoint = referencePoint;
}

void ParametricSurfaceClosestPointNaiveFinder::
        setSamplingResolution(glm::ivec2 samplingResolution)
{
    _samplingResolution = samplingResolution;
}

// 通过均匀采样参数空间，来寻找离指定参考点最近的曲面点的朴素算法
glm::dvec2 ParametricSurfaceClosestPointNaiveFinder::
        find(const IParametricSurfaceUV& surface)
{
    double closestDistance = std::numeric_limits<double>::max();
    glm::dvec2 closestPoint{};

    for (auto x = 0; x < _samplingResolution.x; ++x)
    {
        auto dx = x / static_cast<double>(_samplingResolution.x);
        // 获取对应的v方向曲线
        auto curve = surface.getConstParameterCurve(ParametrizationAxis::U, dx);
        // 遍历该曲线上的点
        for (auto y = 0; y < _samplingResolution.y; ++y)
        {
            auto dy = y / static_cast<double>(_samplingResolution.y);
            auto position = curve->evaluate(dy);    // 返回该参数下的空间点
            auto distance = glm::length(position - _referencePoint);    // 欧氏距离
            // 做比较，更新最近的u，v参数位置
            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestPoint = glm::dvec2{dx, dy};
            }
        }
    }

    return closestPoint;
}

}
