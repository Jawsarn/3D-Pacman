#pragma once
#include "Precompiled.h"
#include "Button.h"
#include "Structs.h"
class MenuManager
{
	//////////////////////Variables///////////////
private:
	//GraphicInterface * graphicInterface
	std::vector<Button> buttons;
	///////////////////////Functions///////////////
public:
	MenuManager();//GraphicInterface * graphicInterface
	~MenuManager(void);

	int Update(UserCMD userCMD);

	void Draw();
};

