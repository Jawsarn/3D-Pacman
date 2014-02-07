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
	bool enrage;
	UserCMD prevCMD;

	//////////////////Functions///////////////
public:
	Pacman();
	~Pacman(void);

	void Update(UserCMD userCMD, float dt);
	void StartDevouring();
	void SetPosition(glm::vec3 _position);

	float GetHunger();

	PacStruct GetPacStruct();

	glm::vec3 GetDirection();
	glm::vec3 GetPosition();
private:
	void OnKey(std::vector<int> keys, float dt);
	void OnMouse(glm::vec2 mousePos);
	void Rotate(float angle,glm::vec3& thisVec, glm::vec3& axis);
};

