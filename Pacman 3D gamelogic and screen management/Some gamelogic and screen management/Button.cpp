#include "Button.h"
#define SCREEN_HEIGHT  1080
#define SCREEN_WIDTH  1920

Button::Button(glm::vec2 _topLeft, glm::vec2 _bottomRight, std::string _buttonName)
{
	topLeft = _topLeft;
	bottomRight = _bottomRight;
	buttonName = _buttonName;
	
}


Button::~Button(void)
{
}

int Button::CheckClick(int x, int y)
{
	float mouseCoordX = (float)(x-SCREEN_WIDTH/2)/(float)(SCREEN_WIDTH/2);
	float mouseCoordY = -(float)(y-SCREEN_HEIGHT/2)/(float)(SCREEN_HEIGHT/2);

	if(mouseCoordX > topLeft.x && mouseCoordX < bottomRight.x && mouseCoordY < topLeft.y && mouseCoordY > bottomRight.y)
	{
		if(buttonName == "Play")
			return GAME_RETURN;
		else if(buttonName == "Highscore")
			return HIGHSCORE_RETURN;
		else if (buttonName == "Menu")
			return MENU_RETURN;
		else if(buttonName == "Quit")
			exit(0);
	}
	return 0;
}