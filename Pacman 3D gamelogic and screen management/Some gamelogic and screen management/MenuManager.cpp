#include "MenuManager.h"



MenuManager::MenuManager(GraphicsHandler* _graphicsHandler,std::vector<std::string>buttonNames)
{
	graphicsHandler = _graphicsHandler;
	int numberOfButtons = buttonNames.size();
	float offsetY = (float)2/(float)(numberOfButtons*2);
	float offsetX = 0.5f;
	for(int i = 0; i<numberOfButtons; i++)
	{
		CreateButton(glm::vec2(0-offsetX,1-i*offsetY),glm::vec2(0+offsetX,1-i*offsetY-offsetY), buttonNames[i]);
	}
}

MenuManager::MenuManager(){};

MenuManager::~MenuManager(void)
{
}
void MenuManager::CreateButton(glm::vec2 topLeft, glm::vec2 bottomRight, std::string buttonName)
{
	buttons.push_back(Button(topLeft, bottomRight, buttonName)); //kanske inte funkar kolla när glm är kopplat
}

void MenuManager::Draw()
{
	//graphicsHandler->DrawMenu(buttons); //DUNNO BOUT THIS YO
}
int MenuManager::Update(UserCMD userCMD)
{
	int clickedButton = MENU_RETURN;
	if(userCMD.mouseClick)
	{
		for(int i =0; i<buttons.size();i++)
		{
			clickedButton = buttons[i].CheckClick(userCMD.deltaMousePosition.x, userCMD.deltaMousePosition.y);
			if(clickedButton != 0)
			{
				return clickedButton;
			}
		}
	}
	
	return clickedButton;
	
}
