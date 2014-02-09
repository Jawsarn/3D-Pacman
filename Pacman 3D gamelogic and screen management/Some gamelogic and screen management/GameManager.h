#pragma once

#include "Structs.h"
#include "Precompiled.h"

#include "GraphicsHandler.h"
#include "AI.h"
#include "Candy.h"
#include "MapLoader.h"
#include "AudioManager.h"
#include "Pacman.h"
class GameManager
{
	//////////////////////Variables/////////////
private:
	AI aI;
	AudioManager audioManager;
	GraphicsHandler* graphicsHandler;
	MapLoader mapLoader;
	Pacman pacman;
	std::vector<Candy> candies;
	std::vector<int> sounds;
	std::vector<std::vector<int>> logicalMap;
	std::vector<glm::vec3> pacmanSpawnPoints;
	
	_int64 prevTimeStamp;
	float secsPerCnt;
	float deltaTime;
	float gameTime;


	/////////////////////Functions///////////////
public:
	GameManager(GraphicsHandler* _graphicsHandler);
	GameManager(void);
	~GameManager(void);
	int Update(UserCMD userCMD);//NS
	void Draw(); //NS
	void Initialize(); // started

private:
	void CheckCollision(glm::vec3 pacPos, std::vector<glm::vec3> ghostPos);//NS
	void CreateEntities();
	void FixMap();//NS
	void LoadMap(const char* mapName, int width, int height);
	void Timer();
};

