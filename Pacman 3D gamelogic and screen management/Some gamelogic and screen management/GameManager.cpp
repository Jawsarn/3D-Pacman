#include "GameManager.h"
#include <Windows.h>

using namespace std;
using namespace glm;

GameManager::GameManager(void)
{
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	secsPerCnt = 1.0f / (float)cntsPerSec;
	prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);
	deltaTime = 0;
	gameTime = 0;
}

GameManager::GameManager(GraphicsHandler* _graphicsHandler)
{
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	secsPerCnt = 1.0f / (float)cntsPerSec;
	prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);
	deltaTime = 0;
	gameTime = 0;

	graphicsHandler = _graphicsHandler;
}

GameManager::~GameManager(void)
{
}

void GameManager::Initialize()
{
	pacman = Pacman();
	mapLoader = MapLoader();
	LoadMap("test.raw",256,256);
}

int GameManager::Update(UserCMD userCMD)
{
	Timer();

	pacman.Update(userCMD, deltaTime);
	aI.Update(deltaTime);
	return GAME_RETURN;
}

void GameManager::Draw(){};


void GameManager::LoadMap(const char* mapName, int width, int height)
{	
	logicalMap = mapLoader.LoadMap(mapName,width,height);
	CreateEntities();

}

void GameManager::CreateEntities()
{
	int width = logicalMap.size();
	int height = logicalMap[0].size();
	candies.clear();
	pacmanSpawnPoints.clear();
	float f = 0;
	f=offset;
	vector<vec3>ghostStartPositions;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (logicalMap[i][j] == 36) //20%
			{
				candies.push_back(Candy(vec3(i*offset,0.2f,j*offset),0));
			}
			else if (logicalMap[i][j] == 80) //40%
			{
				candies.push_back(Candy(vec3(i*offset,0.2f,j*offset),1));
			}
			else if (logicalMap[i][j] == 132) //60%
			{
				pacmanSpawnPoints.push_back(vec3(i*offset,0.2f,j*offset));
			}
			else if (logicalMap[i][j] == 191) //80%
			{
				ghostStartPositions.push_back(vec3(i*offset,0.2f,j*offset));
			}
		}
	}
	int random = rand() % pacmanSpawnPoints.size();
	pacman.SetPosition(pacmanSpawnPoints[random]);
	aI = AI(logicalMap, &pacman.GetPosition(),ghostStartPositions);

}








































void GameManager::Timer()
{
	//timer
	__int64 currTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
	deltaTime = (currTimeStamp - prevTimeStamp) * secsPerCnt;
	prevTimeStamp = currTimeStamp;
	gameTime += deltaTime;
	//
}