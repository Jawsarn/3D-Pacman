#pragma once

#include "Ghost.h"
#include "Structs.h"
#include "Precompiled.h"
class AI
{
	/////////////////Variables////////////////
private:
	std::vector<Ghost> ghosts;
	glm::vec3 * pacmanPosition;
	std::vector<std::vector<int>> logicalMap;
	/////////////////Functions////////////////
public:
	AI();
	AI(std::vector<std::vector<int>> _logicalMap, glm::vec3* pacmanPosition , std::vector<glm::vec3> ghostPositions);
	~AI(void);

	void Update(float dt);
	std::vector<std::vector<GhostStruct>> GetGhostInformation();
private:
	void UpdateGhostPath(glm::vec3* goalPosition , Ghost& ghostToUpdate);
};

