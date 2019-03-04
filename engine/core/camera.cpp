#include "pav_pch.h"
#include "camera.h"

using namespace component; // <-- Keep name the same to the namespace in camera.h


camera::camera(const int viewportWidth, const int viewportHeight, const Vec3 position_)
{
}


camera::~camera()
{
}

void camera::UpdateViewMatrix()
{
	//TODO: updates the matrix and positions/rotations every frame 
}

Matrix4 & camera::getProjectionMatrix()
{
	// TODO: will insert code here
	return projectionMatrix;
}

Matrix4 & camera::getViewMatrix()
{
	// TODO: will insert code here

	return viewMatrix;
}

void camera::setPosition(const Vec3 & position_)
{
	// TODO: sets position of the "camera" (Actually the position of the world in front of the camera)
}

void camera::setRotation(const Vec3 & rotation_)
{
	// TODO: sets position of the camera's rotation
}

void camera::setUpDirection(const Vec3 & dir_)
{
	// TODO: sets the UP vector (which axis points to the sky?)
}
