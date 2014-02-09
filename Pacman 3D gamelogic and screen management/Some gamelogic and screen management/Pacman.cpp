#include "Pacman.h"
#include "Quaternion.h"
using namespace glm;
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4
#define STEP_LENGHT 0.1f
#define mouseAngleScalingValue 40.0f



Pacman::Pacman(void)
{
	maxDevTime = 10;
	devourTime = maxDevTime;
	hunger = 100;
	speed = 5;
	direction = vec3(0,0,1);
	position = vec3(0,100,0);
	up = vec3(0,1,0);
	life = 3;
	enrage = false;
}


Pacman::~Pacman(void)
{
}


void Pacman::SetPosition(vec3 _position)
{
	position = _position;
}

vec3 Pacman::GetPosition()
{
	return position;
}
vec3 Pacman::GetDirection()
{
	return direction;
}

PacStruct Pacman::GetPacStruct()
{
	PacStruct retStruct;
	retStruct.hunger = hunger;
	retStruct.life = life;

	return retStruct;
}

float Pacman::GetHunger()
{
	return hunger;
}

void Pacman::StartDevouring()
{
	devourTime = 0;
	enrage = true;
}

void Pacman::Update(UserCMD userCMD, float dt)
{
	if(enrage)
	{
		devourTime += dt;
		if(devourTime > maxDevTime)
		{
			enrage = false;
		}
	}
	OnMouse(userCMD.deltaMousePosition);
	OnKey(userCMD.keys,dt);
	
}

void Pacman::OnKey(std::vector<int> keys, float dt)
{
	for (int i = 0; i < keys.size(); i++)
	{
		switch (keys[i])
		{
		case KEY_UP:
			{
				position += vec3(direction.x, 0 , direction.z)*STEP_LENGHT*dt;
				break;
			}
		case KEY_DOWN:
			{
				position -= vec3(direction.x, 0 , direction.z)*STEP_LENGHT*dt;
				break;
			}
		case KEY_LEFT:
			{
				vec3 left = glm::cross(up,direction);
				left = glm::normalize(left);
				position += left*STEP_LENGHT*dt;
				break;
			}
		case KEY_RIGHT:
			{
				vec3 right = glm::cross(direction,up);
				right = glm::normalize(right);
				position += right*STEP_LENGHT*dt;
				break;
			}
		default:
			break;
		}
	}
}

void Pacman::OnMouse(vec2 deltaPos)
{
	float angleHorizontal = deltaPos.x/mouseAngleScalingValue;
	float angleVertical = deltaPos.y/mouseAngleScalingValue;



	vec3 verticalAxis(0,1,0);
	
	Rotate(angleHorizontal,direction,verticalAxis);
	normalize(direction);

	vec3 horizontalAxis = cross(verticalAxis,direction);
	normalize(horizontalAxis);
	Rotate(angleVertical, direction, horizontalAxis);

	normalize(direction);

	up = cross(direction,horizontalAxis);
	normalize(up);

}

void Pacman::Rotate(float angle,glm::vec3& thisVec, glm::vec3& axis)
{
	float sinHalfAngle = sinf(glm::radians(angle/2));
	float cosHalfAngle = cosf(glm::radians(angle/2));

	float rx = axis.x*sinHalfAngle;
	float ry = axis.y*sinHalfAngle;
	float rz = axis.z*sinHalfAngle;
	float rw = cosHalfAngle;

	Quaternion rotation(rx, ry, rz, rw);

	Quaternion conjugate = rotation.Conjugate();			//reversed x, y, z: moving camera moves the world the opposte way

	Quaternion w =  rotation*(thisVec)*conjugate;				//p` = qpq^-1 (linjär avbildning)

	thisVec.x=w.x;
	thisVec.y=w.y;
	thisVec.z=w.z;
}