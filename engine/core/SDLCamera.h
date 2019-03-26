#ifndef SDLCAMERA_H
#define SDLCAMERA_H

#include <pav_pch.h>
#include <SDL.h>
#include <gl/GL.h>

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
	GLfloat cameraSpeed;
	GLfloat speedup = 0.5f;
	GLfloat maxspeed = 10.0f;
	GLfloat minspeed = 0.5f;

	//Constructor for initializing the camera.
	SDLCamera(glm::vec3 pos_, glm::vec3 target_, glm::vec3 up_, GLfloat cameraSpeed_);
	~SDLCamera();

	void handleCameraEvents(const SDL_Event& SDLEvent);

	void Update(float deltaTime);


	glm::mat4 getViewMatrix();

};
#endif // !SDLCAMERA_H