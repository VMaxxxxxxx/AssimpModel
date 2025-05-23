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
};  // ö����ӽ�����ɹ����ջ��ع顢δ֪

// �ռ����ߵĽ���ParametricSurfaceIntersection�����һ������_curvePoints��vector���ͣ�
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

    // ��ȡ����
    const std::vector<ParametricSurfaceIntersection> getCurvePoints() const;

protected:
    int findConnectablePoint(
        const ParametricSurfaceIntersection& intersection
    ) const;

private:
    // �ջ�������ñ�־���Ƿ���������������µ�ʱ������Ƿ�ص�����γɱջ�
    bool _isLoopBackEnabled;
    // �������������ϵĲ�����С��ֵ���ڽ�������-������Ҫ���������ٸ����ĵ�ſ��ǻص�֮ǰ�ĵ�
    int _minIndexDiff;
    // ��ǰ�����ʷĳ��֮��ľ���С�ڸ�ֵ���ռ����С�����ֵ����ص���㣬�γɱջ�
    double _loopBackDistance;
    // ���㼯����ɽ���
    std::vector<ParametricSurfaceIntersection> _curvePoints;
};

}
