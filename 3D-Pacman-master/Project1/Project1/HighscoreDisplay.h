#pragma once
#include "Precompiled.h"
#include "Structs.h"
class HighscoreDisplay
{
	/////////////Variables/////////////
private:
	//GraphicInterface* graphicInterface;
	std::vector<unsigned int> highscoreList;
	void* textFont;
	////////////////Functions//////////////
public:
	HighscoreDisplay(void);	//GraphicInterface* graphicInterface;
	~HighscoreDisplay(void);
	int Update(UserCMD userCMD);
	void Draw();
private:
	void ReadHighscore();
};

