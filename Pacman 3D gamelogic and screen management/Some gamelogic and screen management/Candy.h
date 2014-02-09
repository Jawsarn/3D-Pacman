#pragma once
#include "Precompiled.h"
class Candy
{
	enum Type{Normal, Super};
	//////////////////Variables///////////////////
private:
	Type type;
	glm::vec3 position;
	//////////////////Functions///////////////////
public:
	Candy(glm::vec3 _position, int _type);
	~Candy(void);

	glm::vec3 GetPosition(void);
	int GetType(void);

};

