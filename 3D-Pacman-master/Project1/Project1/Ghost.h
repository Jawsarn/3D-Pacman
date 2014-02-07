#pragma once
#include "Precompiled.h"

class Ghost
{
	////////////////Variables/////////////
	enum State{SCARED, NORMAL};
private:
	State state;
	float speed;
	glm::vec3 direction;
	glm::vec3 position;
	std::vector<glm::vec2> path;

	////////////////Functions////////////
public:
	Ghost(glm::vec3 position);//glm::vec3 position
	~Ghost(void);

	bool Update(float dt);
	void SetState(int stateNumber);

	glm::vec3 GetDirection(void);
	glm::vec3 GetPosition(void);

	void SetPath(std::vector<glm::vec2> _path);
};

