#pragma once

#include "glm/glm.hpp"

namespace fw
{
// ģ����
template <typename TVector>
class AABB
{
public:
    AABB(); // Ĭ�Ϲ��캯��
    AABB(const TVector& min, const TVector& max); // ���캯��
    ~AABB(); // ��������

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

// ����Χ���Ƿ���Ч������С�߽������з����Ƿ�С�ڻ�������߽���Ӧ�ķ�����
template <typename TVector>
bool AABB<TVector>::isValid() const
{
    return glm::all(glm::lessThanEqual(min, max));
}

// �жϸ����ĵ��Ƿ��ڰ�Χ���ڲ���
template <typename TVector>
bool AABB<TVector>::contains(const TVector& vec) const
{
    return glm::all(glm::lessThanEqual(min, vec))
        && glm::all(glm::lessThanEqual(vec, max));
}

// ���㵱ǰ��Χ������һ����Χ�еĽ�����������һ���µ�AABB�����ʾ���������
template <typename TVector>
AABB<TVector> AABB<TVector>::intersect(const AABB<TVector> &rhs) const
{
    return AABB<TVector>{
        glm::max(min, rhs.min),
        glm::min(max, rhs.max)
    };
}

}
