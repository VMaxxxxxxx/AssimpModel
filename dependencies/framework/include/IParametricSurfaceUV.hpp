#pragma once

#include "ICurve.hpp"

#include <glm/glm.hpp>

#include <memory>

namespace fw
{

enum class ParametrizationAxis
{
    U,
    V
};

class IParametricSurfaceUV
{
public:
    virtual ~IParametricSurfaceUV() = default;
    // 获取等参数曲线
    virtual std::shared_ptr<ICurve3d> getConstParameterCurve(
        ParametrizationAxis constParameter,
        double parameter
    ) const = 0;
    // 获取某个参数位置的曲面点
    virtual glm::dvec3 getPosition(glm::dvec2 parametrisation) const = 0;
    // 法线向量
    virtual glm::dvec3 getNormal(glm::dvec2 parmetrisation) const = 0;
    // 方向导数，曲面对u，v的偏导数
    virtual glm::dvec3 getDerivativeU(glm::dvec2 parametrisation) const = 0;
    virtual glm::dvec3 getDerivativeV(glm::dvec2 parametrisation) const = 0;
};

}
