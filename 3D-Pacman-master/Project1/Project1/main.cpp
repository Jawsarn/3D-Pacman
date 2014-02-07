#include "GameManager.h"
#include "Structs.h"

int main(void)
{
	GameManager gm = GameManager();

	UserCMD userCMD;
	userCMD.deltaMousePosition = glm::vec2(0,0);
	gm.Initialize();
	while (true)
	{
		userCMD.keys.push_back(1);	
		userCMD.keys.push_back(3);
		userCMD.deltaMousePosition = glm::vec2(0,0);
		gm.Update(userCMD);
	}
	
}