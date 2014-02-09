#include "AI.h"
using namespace std;
using namespace glm;

AI::AI()
{
}

AI::AI(vector<vector<int>> _logicalMap, vec3* _pacmanPosition, std::vector<glm::vec3> ghostPositions)
{
	logicalMap = _logicalMap;
	pacmanPosition = _pacmanPosition;


	for (int i = 0; i < ghostPositions.size(); i++)
	{
		ghosts.push_back(ghostPositions[i]);
		UpdateGhostPath(pacmanPosition, ghosts[i]);
	}
}


AI::~AI(void)
{
}

void AI::Update(float dt)
{
	for (int i = 0; i < ghosts.size(); i++)
	{
		bool dosentNeedToUpdatePath = ghosts[i].Update(dt);
		if (!dosentNeedToUpdatePath)
		{
			UpdateGhostPath(pacmanPosition,ghosts[i]);
		}
	}
}

void AI::UpdateGhostPath(glm::vec3* goalPosition, Ghost& ghostToUpdate)
{
	vector<vec2> path;
	for (int i = 0; i < 10; i++)
	{
		path.push_back(vec2(i,0));
	}
	ghostToUpdate.SetPath(path);
}

