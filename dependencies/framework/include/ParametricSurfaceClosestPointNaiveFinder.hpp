#pragma once

#include "IParametricSurfaceUV.hpp"
#include <glm/glm.hpp>

namespace fw
{
    // �������Բ���
class ParametricSurfaceClosestPointNaiveFinder
{
public:
    ParametricSurfaceClosestPointNaiveFinder();
    virtual ~ParametricSurfaceClosestPointNaiveFinder();

    // ָ��ҪѰ��������Ŀ���
    void setReferencePoint(glm::dvec3 referencePoint);
    // ���ò����ֱ���
    void setSamplingResolution(glm::ivec2 samplingResolution);
    // Ѱ�������Ĳ���
    glm::dvec2 find(const IParametricSurfaceUV& surface);

private:
    glm::dvec3 _referencePoint;
    glm::ivec2 _samplingResolution;
};

}
