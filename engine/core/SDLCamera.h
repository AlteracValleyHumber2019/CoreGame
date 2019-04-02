#ifndef SDLCAMERA_H
#define SDLCAMERA_H

#include <pav_pch.h>
#include <SDL.h>


enum Camera_Movement
{
	FORWARD,
	BACKWARDS,
	LEFT,
	RIGHT
};

class SDLCamera
{

private:

	glm::vec3 cameraTarget;

	glm::vec3 cameraDirection;

	glm::vec3 up;
	glm::vec3 cameraRight;

	glm::vec3 cameraUp;

	glm::vec3 cameraFront;

	glm::mat4 view;



public:
	glm::vec3 cameraPos;
	//The camera speed values
	glm::float32 cameraSpeed;
	glm::float32 speedup = 0.5f;
	glm::float32 maxspeed = 10.0f;
	glm::float32 minspeed = 0.5f;

	//Constructor for initializing the camera.
	SDLCamera(glm::vec3 pos_, glm::vec3 target_, glm::vec3 up_, glm::float32 cameraSpeed_);
	~SDLCamera();

	void handleCameraEvents(const SDL_Event& SDLEvent);

	//Update function for where the camera's looking
	void Update(float deltaTime);

	//Debug for control checking
	void ShowPos();

	glm::mat4 getViewMatrix();


};
#endif // !SDLCAMERA_H