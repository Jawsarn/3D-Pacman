#include "HighscoreDisplay.h"


HighscoreDisplay::HighscoreDisplay(GraphicsHandler* _graphicsHandler)
{
	graphicsHandler = _graphicsHandler;
}

HighscoreDisplay::HighscoreDisplay(void)
{
}


HighscoreDisplay::~HighscoreDisplay(void)
{
}


int HighscoreDisplay::Update(UserCMD userCMD)
{
	return HIGHSCORE_RETURN;
}

void HighscoreDisplay::Draw()
{}


void HighscoreDisplay::ReadHighscore()
{
	FILE* file = fopen("Highscore.txt","r");/////Funkar inte....
	//fopen_s(&file,"Highscore.txt","r");

	if (file == NULL)
	{
		printf("Oh noooo!! Pacman must have eaten the file! \n");
		return;
	}

	while (true)
	{
		unsigned int temp_score = 0;
		fscanf(file, "%u\n", temp_score); //CRASCH
		highscoreList.push_back(temp_score);
	}
	fclose(file);
}