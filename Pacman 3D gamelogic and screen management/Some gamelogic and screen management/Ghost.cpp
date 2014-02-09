#include "Ghost.h"

using namespace glm;

Ghost::Ghost(vec3 _position)
{
	position = _position;
	speed = 0.3f;
}


Ghost::~Ghost(void)
{
}

bool Ghost::Update(float dt)
{//untested
	vec3 goal = vec3(path[0].x , position.y , path[0].y);
	direction = goal - position;
	normalize(direction);
	vec3 temp_position = position + direction*dt*speed;

	float prevToCurr = length(temp_position - position);
	float prevToGoal = length(goal - position);

	while(prevToCurr > prevToGoal)
	{
		position = goal;

		float distance = prevToCurr - prevToGoal;

		path.erase(path.begin());
		if (path.size() != 0)
		{
			return false;
		}

		goal = vec3(path[0].x , position.y , path[0].y);
		direction = goal - position;
		normalize(direction);

		temp_position = position + direction*distance;
		prevToCurr = length(temp_position - position);
		prevToGoal = length(goal - position);
	}
	if (prevToCurr == prevToGoal)
	{
		position = temp_position;
		path.erase(path.begin());
		if (path.size() != 0)
		{
			return false;
		}
	}
	position = temp_position;
	return true;
}

void Ghost::SetState(int stateNumber)
{
	state = (State)stateNumber;
}

vec3 Ghost::GetDirection()
{
	return direction; 
}

vec3 Ghost::GetPosition()
{
	return position; 
}

void Ghost::SetPath(std::vector<glm::vec2> _path)
{
	path = _path;
}