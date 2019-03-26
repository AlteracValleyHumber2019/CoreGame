#include <pav_pch.h>
#include "SDLCamera.h"
#include <iostream>


SDLCamera::SDLCamera(glm::vec3 pos_, glm::vec3 target_, glm::vec3 up_, GLfloat cameraSpeed_)
{
	cameraPos = pos_;
	cameraTarget = target_;
	up = up_;

	cameraSpeed = cameraSpeed_;

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	cameraDirection = glm::normalize(cameraPos - cameraTarget);

	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);

	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
}

void SDLCamera::handleCameraEvents(const SDL_Event& SDLEvent)
{
	switch (SDLEvent.type) {
		//Implementation of all current camera controls
	case SDL_KEYDOWN:
		switch (SDLEvent.key.keysym.sym) {
		case SDLK_w:
			cameraPos += cameraSpeed * cameraFront;
			break;
		case SDLK_s:
			cameraPos -= cameraSpeed * cameraFront;
			break;
		case SDLK_a:
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			break;
		case SDLK_d:
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			break;

			//Y-Axis Movement (Up and Down)

		case SDLK_SPACE:
			if (cameraPos.y >= 20.0f) {
				cameraPos.y = 20.0f;
			}
			else { cameraPos.y += cameraUp.y * cameraSpeed; }

			break;
		case SDLK_LSHIFT:
			if (cameraPos.y <= 0.0f) {
				cameraPos.y = 0.0f;
			}
			else { cameraPos.y -= cameraUp.y * cameraSpeed; }
			break;

			//Camera Speed Change----------------------------------------------------
		case SDLK_PAGEUP:
			cameraSpeed += speedup;
			std::cout << "speeding up to: " << cameraSpeed << std::endl;
			if (cameraSpeed >= maxspeed) { cameraSpeed = maxspeed; }
			break;

		case SDLK_PAGEDOWN:
			cameraSpeed -= speedup;
			std::cout << "slowing down to: " << cameraSpeed << std::endl;
			if (cameraSpeed <= minspeed) { cameraSpeed = minspeed; }
			break;
			//------------------------------------------------------------------------
		}

		break;
	default:
		break;
	}

}


void SDLCamera::Update(float deltaTime) {

	view = glm::lookAt(cameraPos,
		cameraPos + cameraFront,
		cameraUp);

}

glm::mat4 SDLCamera::getViewMatrix() {

	return view;
}


SDLCamera::~SDLCamera()
{
}