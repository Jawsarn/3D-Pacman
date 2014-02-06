#pragma once
#include "Structs.h"
#include "Precompiled.h"
class Pacman
{
	//////////////////Variables////////////////
private:
	float devourTime;
	float hunger;
	float maxDevTime;
	float speed;
	glm::vec3 direction;
	glm::vec3 position;
	glm::vec3 up;
	unsigned int life;

	//////////////////Functions///////////////
public:
	Pacman(glm::vec3 startPosition);
	~Pacman(void);

	void Update(UserCMD userCMD);
	void StartDevouring();

	float GetHunger();

	PacStruct GetPacStruct();

	glm::vec3 GetDirection();
	glm::vec3 GetPosition();
};

