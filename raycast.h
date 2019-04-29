#ifndef RAYCAST
#define RAYCAST

class raycast
{
	//length of ray
	int RECURSION_COUNT = 200;
	float RAY_RANGE = 600;

	//ray coming from mouse
	Vec3 currentRay;

	//used for converting 2d coordinates on screen ot 3d ray in scene
	Mat4 projectionMatrix;
	Mat4 viewMatrix;

	//camera used for getting view matrix
	Camera camera;

public:
	//constructor set camera and projection matrix variables
	//creating view matrix
	raycast(Camera cam, Mat4 projection);

	//update values
	void update();

	//convert 2d mouse position to 3d ray
	Vec3 calculateMouseRay();

	//convert from eye coordinates to world coordinates
	Vec3 toWorldCoords(Vec4 eyeCoords);

	//convert from clip space to eye space coordinates
	Vec4 toEyeCoords(Vec4 clipCoords);

	//convert mouse coordinates to opengl coordinates
	//returns mouse position, but in opengl coordinates
	Vector2f getNormalisedDeviceCoordinates(float mouseX, float mouseY);

	//get point on ray that intersects with object in scene
	Vec3 getPointOnRay(Vec3 ray, float distance);

	//ray checks for intersection point
	Vec3 binarySearch(int count, float start, float finish, Vec3 ray);
};

#endif