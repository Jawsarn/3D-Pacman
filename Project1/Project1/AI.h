#pragma once

#include "Ghost.h"
#include "Structs.h"
#include "Precompiled.h"
class AI
{
	/////////////////Variables////////////////
private:
	Ghost ghosts[4];
	glm::vec3 * pacmanPosition;
	std::vector<std::vector<int>> logicalMap;
	/////////////////Functions////////////////
public:
	AI(std::vector<std::vector<int>> logicalMap, glm::vec3 pacmanPosition);
	~AI(void);

	void Update();
	std::vector<std::vector<GhostStruct>> GetGhostInformation();
private:
	void UpdateGhostPath(glm::vec3* goalPosition);
};

