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

// �����ջ����
void IntersectionCurve::setLooping(bool loopAllowed)
{
    _isLoopBackEnabled = loopAllowed;
}

// �������б��е��������ٲ�n�����ж�Ϊ�ջ�
void IntersectionCurve::setLoopbackMinimumIndexDifference(int minIndexDiff)
{
    _minIndexDiff = minIndexDiff;
}

// ���ñջ��Ŀռ�����ж���ֵ
void IntersectionCurve::setLoopBackDistance(double loopBackDistance)
{
    _loopBackDistance = loopBackDistance;
}

// ���һ���µĽ��㵽�����У�intersection�µĽ�������
IntersectionCurveAddingResult IntersectionCurve::addCurvePoint(
    const ParametricSurfaceIntersection& intersection
)
{
    if (_isLoopBackEnabled)
    {
        auto connectableIndex = findConnectablePoint(intersection);
        if (connectableIndex >= 0)
        {
            // ���صĵ㣬��Ϊһ�����
            _curvePoints.push_back(_curvePoints[connectableIndex]);
            return IntersectionCurveAddingResult::LoopedBack;
        }
    }

    _curvePoints.push_back(intersection);
    return IntersectionCurveAddingResult::Success;
}

// ��ȡ��ǰ���ߵ��б���
const std::vector<ParametricSurfaceIntersection>
        IntersectionCurve::getCurvePoints() const
{
    return _curvePoints;
}

// ��ת���ߵ��˳����λ������
void IntersectionCurve::reverse()
{
    std::reverse(std::begin(_curvePoints), std::end(_curvePoints));
}

// �����е��м�������½���intersection���Աջ��ĵ�
int IntersectionCurve::findConnectablePoint(
    const ParametricSurfaceIntersection& intersection
) const
{
    // ��������ֱ���жϲ�����ɱջ�����ֹǰ���������гɱջ�
    if (_curvePoints.size() < _minIndexDiff) { return -1; }

    // ֻ���ȵ�ǰ����ܶ�Ľ���
    for (auto i = 0; i < _curvePoints.size() - _minIndexDiff; ++i)
    {
        // ������ʷ��͵�ǰ��Ŀռ������������ֵ
        auto diffVector =
            _curvePoints[i].scenePosition - intersection.scenePosition;

        // ����ŷ����ü�¼�ж��Ƿ�ջ������رջ��������
        if (glm::length(diffVector) < _loopBackDistance)
        {
            return i;
        }
    }

    return -1;
}

}
