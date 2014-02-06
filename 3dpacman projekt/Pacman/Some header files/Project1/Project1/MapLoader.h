#pragma once
#include "Precompiled.h"
class MapLoader
{
	////////////////Functions//////////////
public:
	MapLoader(void);
	~MapLoader(void);
	std::vector<std::vector<int>> LoadMap(const char* mapName);
};

