#include "ScreenManager.h"
#include "GameManager.h"
#include "Structs.h"

int main(void)
{
	ScreenManager sm= ScreenManager();
	GameManager gm = GameManager();

	UserCMD userCMD;
	userCMD.deltaMousePosition = glm::vec2(0,0);
	gm.Initialize();
	while (true)
	{
		userCMD.keys.push_back(1);	
		userCMD.keys.push_back(3);
		userCMD.deltaMousePosition = glm::vec2(SCREEN_WIDTH/2,1);
		userCMD.mouseClick = true;
		//gm.Update(userCMD);
		sm.Update();
	}
	
}