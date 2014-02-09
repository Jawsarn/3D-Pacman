#pragma once
#include "Precompiled.h"
#include "Button.h"
#include "Structs.h"
#include "GraphicsHandler.h"
class MenuManager
{
	//////////////////////Variables///////////////
private:
	GraphicsHandler* graphicsHandler;
	std::vector<Button> buttons;
	///////////////////////Functions///////////////
public:
	MenuManager();
	MenuManager(GraphicsHandler* _graphicsHandler, std::vector<std::string>buttonNames);
	~MenuManager(void);
	int Update(UserCMD userCMD);
	void Draw();
private:
	void CreateButton(glm::vec2 topLeft, glm::vec2 bottomRight, std::string buttonName);
};

