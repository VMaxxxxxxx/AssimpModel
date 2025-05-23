#ifndef __ORBITING_CAMERA_HPP__
#define __ORBITING_CAMERA_HPP__

#include <glm/mat4x4.hpp>

class OrbitingCamera {
public:
	// 初始化旋转角度限制、摄像机到目标点的距离
  OrbitingCamera();

  inline void setMinXRotation(float min) { _xMin = min; }
  inline void setMaxXRotation(float max) { _xMax = max; }

  inline float getDist() { return _dist; }
  inline void setDist(float dist) { _dist = dist; }
  // 更新摄像机的旋转角度
  void rotate(float dx, float dy);
  // 获取摄像机的视图矩阵、在世界坐标系的位置
  glm::mat4 getViewMatrix() const;
  glm::vec3 getPosition() const;

private:
	// 摄像机绕水平轴旋转的最小、最大角度
  float _xMin, _xMax;
  // 摄像机到目标点的距离
  float _dist;	
  // 摄像机绕水平轴、垂直轴的旋转角度
  float _rotationX, _rotationY;
  

};

#endif
