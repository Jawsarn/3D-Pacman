#include "ScreenManager.h"

using namespace std; 
ScreenManager::ScreenManager(void)
{
	state = HIGHSCORE;
	graphicsHandler = GraphicsHandler();
	gameManager = GameManager(&graphicsHandler);
	vector<string> buttonNames;
	buttonNames.push_back("Play");
	buttonNames.push_back("Highscore");
	buttonNames.push_back("Quit");
	buttonNames.push_back("hejsan");
	menuManager = MenuManager(&graphicsHandler, buttonNames);
}


ScreenManager::~ScreenManager(void)
{
}

void ScreenManager::KeyboardCallback(int key)
{
	userCMD.keys.push_back(key);
}
void ScreenManager::MouseCallback(int button, int state, int x, int y)
{
	
	userCMD.deltaMousePosition.x += x;
	userCMD.deltaMousePosition.y += y;

	if(button == 1 && state == 2) //kanske fixa hårdavärden istället för glut_down/up för att slippa includa glut
	{
		userCMD.mouseClick = true;
	}
	else if(button == 2 && state == 1)
	{
		userCMD.mouseClick = false;
	}
}
void ScreenManager::UserCMDReset()
{
	userCMD.keys.clear();
	if(state == GAME)
	{
		userCMD.deltaMousePosition.x = SCREEN_HEIGHT/2;
		userCMD.deltaMousePosition.y = SCREEN_WIDTH/2;
	}
		
}
void ScreenManager::Update()
{
	userCMD.keys.push_back(1);	
	userCMD.keys.push_back(3);
	userCMD.deltaMousePosition = glm::vec2(SCREEN_WIDTH/2 + 3,1);
	userCMD.mouseClick = true;
	static bool needsToReadHighscore = true;
	if(state == MENU)
	{
		state = (State)menuManager.Update(userCMD);
		needsToReadHighscore = true;
		UserCMDReset();
		menuManager.Draw();
	}
	else if(state==GAME)
	{
		state = (State)gameManager.Update(userCMD);
		needsToReadHighscore = true;
		UserCMDReset();
		
		gameManager.Draw();
	}
	else if(state == HIGHSCORE)
	{
		if (needsToReadHighscore)
		{
			highscoreDisplay.ReadHighscore();
			needsToReadHighscore = false;
		}
		state = (State)highscoreDisplay.Update(userCMD);
		UserCMDReset();
		highscoreDisplay.Draw();
	}
}

