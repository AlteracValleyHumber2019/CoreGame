#ifndef CAMERA_H
#define	CAMERA_H

#include <pav_pch.h>
#include <gl/GL.h>
/**
 * \class	camera
 *
 * \brief	will be used in conjunction with scene in order to create scene movement with perspective
 *
 * \state   Template with methods and variables ready to be filled and connected by [Component]
 *
 * \
 *
 * \author	Brandon_P
 * \date	3/3/2019 ->> 3/4/2019
 */

enum Camera_Movement
{
	FORWARD,
	BACKWARDS,
	LEFT,
	RIGHT
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 8.0f;
const GLfloat SENSITIVITY = 0.4f; //Mouse Sensitivity
const GLfloat FOV = 45.0f; //Field of VIew

class camera
{
private:
	//Camera location Values
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUP;

	//Camera rotation values
	glm::vec3 yaw;
	glm::vec3 pitch;

	//Camera movement values
	glm::vec3 movementSpeed;
	glm::vec3 mouseSensitivity;
	glm::vec3 fov;

	void updateCamera(float deltaTime)
	{
		glm::vec3 front;

		front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		front.y = sin(glm::radians(this->pitch));
		front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

		this->front = glm::normalize(front);
		this->right = glm::normalize(glm::cross( this->front, this->worldUP));
		this->up = glm::normalize(glm::cross(this->right, this->front));
	}

public:

	camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH): front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), fov(FOV){

		this->position = position;
		this->worldUP = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCamera();
		}

	camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch): front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY), fov(FOV){

	this->position = glm::vec3(posX, posY, posZ);
	this->worldUP = glm::vec3(upX, upY, upZ);;
	this->yaw = yaw;
	this->pitch = pitch;
	this->updateCamera();
	}

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(this->position, this->position + this->front, this->up);
	}

	glm::mat4 lookAt()

	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
	{
		GLfloat velocity = this->movementSpeed * deltaTime;

		if (FORWARD == direction)
		{
			this->position += this->front * velocity;
		}
		if (BACKWARDS == direction)
		{
			this->position -= this->front * velocity;
		}
		if (LEFT == direction)
		{
			this->position -= this->right * velocity;
		}
		if (RIGHT == direction)
		{
			this->position += this->right * velocity;
		}

	}

	void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constraintPitch = true)
	{
		xOffset *= this->mouseSensitivity;
		yOffset *= this->mouseSensitivity;

		this->yaw += xOffset;
		this->pitch += yOffset;
		//Prevent Screen from flipping 
		if (constrainPitch)
		{
			if (this->pitch > 89.0f)
			{
				this->pitch = 89.0f;
			}

			if (this->pitch < -89.0f)
			{
				this->pitch = -89.0f;
			}

		}

		this->updateCamera();
	}

	void ProccessMouseScroll(GLfloat yOffset) {
		if(this->fov >= 1.0f && this->fov <=45.0f)
		{
			this->fov -= yOffset;
		}

		if (this->fov <= 1.0f)
		{
			this->fov = 1.0f;
		}

		if (this->fov >= 45.0f)
		{
			this->fov = 45.0f;
		}

	}

	GLfloat GetZoom()
	{
		return this->fov;
	}

	glm::vec3 GetPosition()
	{
		return this->position;
	}

	glm::vec3 GetFront()
	{
		return this->front;
	}
}



#endif