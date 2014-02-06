#pragma once
#include "Precompiled.h"
class Candy
{
	enum Type{Super, Normal};
	//////////////////Variables///////////////////
private:
	Type type;
	glm::vec3 position;
	//////////////////Functions///////////////////
public:
	Candy(glm::vec3 position);
	~Candy(void);

	glm::vec3 GetPosition(void);
	int GetType(void);

};

