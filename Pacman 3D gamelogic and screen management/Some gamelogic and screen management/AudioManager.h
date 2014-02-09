#pragma once
#include "Precompiled.h"
class AudioManager
{
	/////////////////Variables//////////////
private:
	//ALuint audioBuffer[NUM_OF_SOUNDS];
	int soundCounter;
public:
	AudioManager(void);
	~AudioManager(void);
	int CreateSound(const char* fileName);
	void PlaySound(int sound, glm::vec3 soundPosition);
	void Update(glm::vec3 headPosition, glm::vec3 headDirection);
};

