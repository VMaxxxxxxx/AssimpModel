#pragma once
#include "ParametricSurfaceIntersection.hpp"
#include <vector>

namespace fw
{

enum class IntersectionCurveAddingResult
{
    Unknown,
    Success,
    LoopedBack
};  // 枚举添加结果：成功、闭环回归、未知

// 收集曲线的交点ParametricSurfaceIntersection，组成一条曲线_curvePoints（vector类型）
class IntersectionCurve
{
public:
    IntersectionCurve();
    ~IntersectionCurve();

    void setLooping(bool loopAllowed);
    void setLoopbackMinimumIndexDifference(int minIndexDiff);
    void setLoopBackDistance(double loopBackDistance);

    IntersectionCurveAddingResult addCurvePoint(
        const ParametricSurfaceIntersection& intersection
    );

    void reverse();

    // 获取交线
    const std::vector<ParametricSurfaceIntersection> getCurvePoints() const;

protected:
    int findConnectablePoint(
        const ParametricSurfaceIntersection& intersection
    ) const;

private:
    // 闭环检测启用标志，是否允许曲线在添加新点时，检测是否回到起点形成闭环
    bool _isLoopBackEnabled;
    // 两个点在索引上的差异最小阈值，在交点数组-交线中要经历的最少个数的点才考虑回到之前的点
    int _minIndexDiff;
    // 当前点和历史某点之间的距离小于该值，空间距离小于这个值就算回到起点，形成闭环
    double _loopBackDistance;
    // 交点集，组成交线
    std::vector<ParametricSurfaceIntersection> _curvePoints;
};

}
