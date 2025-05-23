#pragma once

#include "glm/glm.hpp"

namespace fw
{
// 模板类
template <typename TVector>
class AABB
{
public:
    AABB(); // 默认构造函数
    AABB(const TVector& min, const TVector& max); // 构造函数
    ~AABB(); // 析构函数

    bool isValid() const;
    bool contains(const TVector& vec) const;
    AABB<TVector> intersect(const AABB<TVector> &rhs) const;

    TVector min;
    TVector max;
};

template <typename TVector>
AABB<TVector>::AABB():
    min{},
    max{}
{
}

template <typename TVector>
AABB<TVector>::AABB(const TVector& min, const TVector& max):
    min{min},
    max{max}
{
}

template <typename TVector>
AABB<TVector>::~AABB()
{
}

// 检查包围盒是否有效，即最小边界点的所有分量是否小于或等于最大边界点对应的分量。
template <typename TVector>
bool AABB<TVector>::isValid() const
{
    return glm::all(glm::lessThanEqual(min, max));
}

// 判断给定的点是否在包围盒内部。
template <typename TVector>
bool AABB<TVector>::contains(const TVector& vec) const
{
    return glm::all(glm::lessThanEqual(min, vec))
        && glm::all(glm::lessThanEqual(vec, max));
}

// 计算当前包围盒与另一个包围盒的交集，并返回一个新的AABB对象表示这个交集。
template <typename TVector>
AABB<TVector> AABB<TVector>::intersect(const AABB<TVector> &rhs) const
{
    return AABB<TVector>{
        glm::max(min, rhs.min),
        glm::min(max, rhs.max)
    };
}

}
