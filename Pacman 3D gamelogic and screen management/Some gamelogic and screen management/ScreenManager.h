#pragma once
#include "Precompiled.h"
#include "Structs.h"
#include "GameManager.h"
#include "MenuManager.h"
#include "HighscoreDisplay.h"
#include "GraphicsHandler.h"

class ScreenManager
{
	enum State{MENU, GAME, HIGHSCORE};
	////////////////Variables//////////////////
private:
	State state;
	GameManager gameManager;
	HighscoreDisplay highscoreDisplay;
	MenuManager menuManager;
	UserCMD userCMD;
	GraphicsHandler graphicsHandler;

	///////////////Functions//////////////////////////
public:
	ScreenManager();
	ScreenManager(int argc, char** argv);
	~ScreenManager(void);
	//void Initialize(int argc, char** argv);
	void Update();
private:
	void KeyboardCallback(int key);
	void MouseCallback(int button, int state, int x, int y);
	void UserCMDReset();
	
};

