#pragma once

#include <glm/glm.hpp>
#include <memory>

namespace fw
{

template<typename TPoint, typename TFloating>
class ICurve
{
public:
    virtual ~ICurve() = default;
    // ��ĳ�������µ����ߵ�
    virtual TPoint evaluate(TFloating parameter) const = 0;
    // ��ȡһ�׵�������
    virtual std::shared_ptr<ICurve<TPoint, TFloating>> getDerivativeCurve(
    ) const = 0;
};

using ICurve3f = ICurve<glm::vec3, float>;
using ICurve3d = ICurve<glm::dvec3, double>;

}
