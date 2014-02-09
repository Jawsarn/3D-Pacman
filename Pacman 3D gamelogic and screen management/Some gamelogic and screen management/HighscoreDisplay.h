#pragma once
#include "Precompiled.h"
#include "Structs.h"
#include "Button.h"
#include "GraphicsHandler.h"
class HighscoreDisplay
{
	/////////////Variables/////////////
private:
	GraphicsHandler* graphicsHandler;
	std::vector<unsigned int> highscoreList;
	//Button button;
	void* textFont;
	////////////////Functions//////////////
public:
	HighscoreDisplay(GraphicsHandler* _graphicsHandler);
	HighscoreDisplay(void);	
	~HighscoreDisplay(void);
	int Update(UserCMD userCMD);
	void Draw();
	void ReadHighscore();
};

