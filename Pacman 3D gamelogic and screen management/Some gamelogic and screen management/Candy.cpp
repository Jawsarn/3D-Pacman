#include "Candy.h"


Candy::Candy(glm::vec3 _position, int _type)
{
	position = _position;
	type = (Type)_type;
}


Candy::~Candy(void)
{
}

glm::vec3 Candy::GetPosition()
{
	return position;
}

int Candy::GetType()
{
	return type;
}