#include <pav_pch.h>
#include "SDLCamera.h"
#include <iostream>


SDLCamera::SDLCamera(glm::vec3 pos_, glm::vec3 target_, glm::vec3 up_, glm::float32 cameraSpeed_)
{
	cameraPos = pos_;
	cameraTarget = target_;
	up = up_;

	cameraSpeed = cameraSpeed_;

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	CheckCameraCreation();
	ShowPos();
}


void SDLCamera::Update(float deltaTime) {

	view = glm::lookAt(cameraPos,
		cameraPos + cameraFront,
		cameraUp);

}

//Debug Methods------------------------------------------------------------------------------------------------------------
void SDLCamera::ShowPos()
{
	std::cout << "Camera position: " << cameraPos.x << ", " << cameraPos.y << ", " << cameraPos.z << std::endl;
	std::cout << "Camera target: " << cameraFront.x << ", " << cameraFront.y << ", " << cameraFront.z << std::endl;
}

void SDLCamera::CheckCameraCreation()
{
	std::cout << "Camera created in scene Scussfully." << std::endl;
}
//------------------------------------------------------------------------------------------------------------------------

glm::mat4 SDLCamera::getViewMatrix() {

	return view;
}

/*Movement Camera Rotate

float radius = 10.0f;
float camX = sin(glfwGetTime()) * radius;
float camZ = cos(glfwGetTime()) * radius;
glm::mat4 view;
view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
*/


SDLCamera::~SDLCamera()
{
}