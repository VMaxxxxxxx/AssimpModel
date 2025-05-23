#include "IntersectionCurve.hpp"
//modify
#include <algorithm>
//end
namespace fw
{

IntersectionCurve::IntersectionCurve():
    _isLoopBackEnabled{false},
    _loopBackDistance{},
    _minIndexDiff{}
{
}

IntersectionCurve::~IntersectionCurve()
{
}

// 开启闭环检测
void IntersectionCurve::setLooping(bool loopAllowed)
{
    _isLoopBackEnabled = loopAllowed;
}

// 两点在列表中的索引至少差n才能判定为闭环
void IntersectionCurve::setLoopbackMinimumIndexDifference(int minIndexDiff)
{
    _minIndexDiff = minIndexDiff;
}

// 设置闭环的空间距离判定阈值
void IntersectionCurve::setLoopBackDistance(double loopBackDistance)
{
    _loopBackDistance = loopBackDistance;
}

// 添加一个新的交点到曲线中，intersection新的交点数据
IntersectionCurveAddingResult IntersectionCurve::addCurvePoint(
    const ParametricSurfaceIntersection& intersection
)
{
    if (_isLoopBackEnabled)
    {
        auto connectableIndex = findConnectablePoint(intersection);
        if (connectableIndex >= 0)
        {
            // 返回的点，作为一个起点
            _curvePoints.push_back(_curvePoints[connectableIndex]);
            return IntersectionCurveAddingResult::LoopedBack;
        }
    }

    _curvePoints.push_back(intersection);
    return IntersectionCurveAddingResult::Success;
}

// 获取当前交线的列表副本
const std::vector<ParametricSurfaceIntersection>
        IntersectionCurve::getCurvePoints() const
{
    return _curvePoints;
}

// 反转曲线点的顺序（首位互换）
void IntersectionCurve::reverse()
{
    std::reverse(std::begin(_curvePoints), std::end(_curvePoints));
}

// 在已有点中间查找与新交点intersection可以闭环的点
int IntersectionCurve::findConnectablePoint(
    const ParametricSurfaceIntersection& intersection
) const
{
    // 不够长，直接判断不能组成闭环，防止前几个点误判成闭环
    if (_curvePoints.size() < _minIndexDiff) { return -1; }

    // 只看比当前点早很多的交点
    for (auto i = 0; i < _curvePoints.size() - _minIndexDiff; ++i)
    {
        // 计算历史点和当前点的空间坐标的向量差值
        auto diffVector =
            _curvePoints[i].scenePosition - intersection.scenePosition;

        // 根据欧几里得记录判断是否闭环，返回闭环点的索引
        if (glm::length(diffVector) < _loopBackDistance)
        {
            return i;
        }
    }

    return -1;
}

}
