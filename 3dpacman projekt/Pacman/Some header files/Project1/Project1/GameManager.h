#pragma once

#include "Structs.h"
#include "Precompiled.h"
class GameManager
{
public:
	GameManager(void);
	~GameManager(void);
	int Update(UserCMD userCMD);
	void Draw();
	void Initialize();

private:
	void CheckCollision(glm::vec3 pacPos, std::vector<glm::vec3> ghostPos);
	void CreateCandies();
	void FixMap();
	void LoadMap(const char* mapName);
};

