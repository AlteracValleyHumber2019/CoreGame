#include "raycast.h"

//raycasting (mousePicking): "pick" a 3d object in scene using mouse cursor
//project a 3d ray from mouse, through the camera, into the scene, then check for intersection with objects

raycast::raycast(Camera cam, Mat4 projection) {
	camera = cam;
	projectionMatrix = projection;
	viewMatrix = createViewMatrix(camera);
}

void raycast::update() {
	//every frame, create a new view matrix using camera
	viewMatrix = inverse(camera);

	//update current mouse ray
	currentRay = calculateMouseRay();
}

Vec3 raycast::calculateMouseRay() {
	//mouse coordinate on screen
	float mouseX = Mouse.getX();
	float mouseY = Mouse.getY();

	//coordinates convert 2d to opengl coordinates
	Vec2 normalizedCoords = getNormalisedDeviceCoordinates(mouseX, mouseY);

	//ray points into the screne, not outwards
	Vec4 clipCoords = new Vec4(normalizedCoords.x, normalizedCoords.y, -1.0f, 1.0f);
	Vec4 eyeCoords = toEyeCoords(clipCoords);
	Vec4 worldRay = toWorldCoords(eyeCoords);
	return worldRay;
}

//eye to world
Vec3 raycast::toWorldCoords(Vec4 eyeCoords) {
	Vec4 invertedView = Vec4.invert(viewMatrix, nullptr);
	Vec4 rayWorld = Vec4.transform(invertedView, eyeCoords, nullptr);
	Vec3 mouseRay = new Vec3(rayWorld.x, rayWorld.y, rayWorld.z);
	mouseRay.normalize();
	return mouseRay;
}

//clip space to eye space
Vec4 raycast::toEyeCoords(Vec4 clipCoords) {
	Mat4 invertedProjection = Mat4.invert(projectionMatrix, nullptr);
	Vec4 eyeCoords = Mat4.transform(invertedProjection, clipCoords, nullptr);
	return new Vec4(eyeCoords.x, eyeCoords.y, -1.0f, 0.0f);
}

//screen, to world coordinates (in scene)
Vec2 raycast::getNormalisedDeviceCoordinates(float mouseX, float mouseY) {
	float x = (2.0f * mouseX) / Display.getWidth() - 1f;
	float y = (2.0f * mouseY) / Display.getHeight() - 1f;
	return new Vector2f(x, y);
}

//get intersection point on ray by creating a new scaled ray 
Vec3 raycast::getPointOnRay(Vec3 ray, float distance) {
	Vec3 camPos = camera.getPosition();
	Vec3 start = new Vec3(camPos.x, camPos.y, camPos.z);
	Vec3 scaledRay = new Vec3(ray.x * distance, ray.y * distance, ray.z * distance);
	return Vec3.add(start, scaledRay, nullptr);
}

//checks for intersection
Vec3 raycast::binarySearch(int count, float start, float finish, Vec3 ray) {
	//get ray midpoint
	float half = start + ((finish - start) / 2.0f);
	if (count >= RECURSION_COUNT) {
		Vec3 endPoint = getPointOnRay(ray, half);

	}
	//if the inersection is in the first half of the ray, recurse the ray, but ++count
	//else, the intersection must happen in the bottom half of the ray
	if (intersectionInRange(start, half, ray)) {
		return binarySearch(count + 1, start, half, ray);
	}
	else {
		return binarySearch(count + 1, half, finish, ray);
	}
}