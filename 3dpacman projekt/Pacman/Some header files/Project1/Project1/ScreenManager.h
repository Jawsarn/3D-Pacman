#pragma once
#include "Precompiled.h"
#include "Structs.h"
#include "GameManager.h"
#include "MenuManager.h"
#include "HighscoreDisplay.h"

class ScreenManager
{
	enum State{Game, Menu, Highscore};
	////////////////Variables//////////////////
private:
	State state;
	GameManager gameManager;
	HighscoreDisplay highscoreDisplay;
	MenuManager menuManager;
	UserCMD userCMD;

	///////////////Functions//////////////////////////
public:
	ScreenManager(void);
	~ScreenManager(void);
	int Main(int argc, char** argv);
private:
};

