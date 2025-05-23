#ifndef __ORBITING_CAMERA_HPP__
#define __ORBITING_CAMERA_HPP__

#include <glm/mat4x4.hpp>

class OrbitingCamera {
public:
	// ��ʼ����ת�Ƕ����ơ��������Ŀ���ľ���
  OrbitingCamera();

  inline void setMinXRotation(float min) { _xMin = min; }
  inline void setMaxXRotation(float max) { _xMax = max; }

  inline float getDist() { return _dist; }
  inline void setDist(float dist) { _dist = dist; }
  // �������������ת�Ƕ�
  void rotate(float dx, float dy);
  // ��ȡ���������ͼ��������������ϵ��λ��
  glm::mat4 getViewMatrix() const;
  glm::vec3 getPosition() const;

private:
	// �������ˮƽ����ת����С�����Ƕ�
  float _xMin, _xMax;
  // �������Ŀ���ľ���
  float _dist;	
  // �������ˮƽ�ᡢ��ֱ�����ת�Ƕ�
  float _rotationX, _rotationY;
  

};

#endif
