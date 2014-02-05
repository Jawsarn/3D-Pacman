#pragma once
#include "Precompiled.h"

struct UserCMD
{
	glm::vec2 mousePosition;
	int key;
};

struct GhostStruct
{
	glm::vec3 direction;
	glm::vec3 position;
};

struct PacStruct
{
	float hunger;
	unsigned int life;
};

struct CameraStruct
{
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;
};