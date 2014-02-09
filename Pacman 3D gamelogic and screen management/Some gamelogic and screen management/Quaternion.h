#pragma once
#include "Precompiled.h"
struct Quaternion
{
	Quaternion(float _x, float _y, float _z, float _w);
	void Normalize();
	Quaternion Conjugate();
	
	float x,y,z,w;
};

Quaternion operator*(const Quaternion& l, const Quaternion& r);
Quaternion operator*(const Quaternion& q, const glm::vec3& v);