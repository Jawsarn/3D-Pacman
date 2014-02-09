#pragma once
#include <string>
#include "Precompiled.h"
class Button
{
public:
	Button(glm::vec2 _topLeft, glm::vec2 _bottomRight, std::string _buttonName);
	Button();
	~Button(void);
	
	glm::vec2  topLeft, bottomRight;
	
	std::string buttonName;
	int CheckClick(int x, int y);   //Stuff måste includas å länkas å krejjer

};

