#ifndef CAMERA_H
#define	CAMERA_H

#include "math\MMath.h"

using namespace MATH;

/**
 * \class	camera
 *
 * \brief	will be used in conjunction with scene in order to create scene movement with perspective
 *
 * \state   Template with methods and variables ready to be filled and connected by [Component]
 *
 * \Also imported Vector and MMath code in case groups need to use their Vector or Matrix methods
 *
 * \author	Brandon_P
 * \date	3/3/2019 ->> 3/4/2019
 */

namespace component {//namespace subject to change

	class camera
	{
	private:
		// Type of camera Lens (Wide View or Focus View)
		Matrix4 projectionMatrix;
		Matrix4 viewMatrix;

		//Camera Variables
		Vec3 position;
		Vec3 rotation;
		Vec3 direction, target;
		Vec3 front, up;


	public:
		camera(const int viewportWidth, const int viewportHeight, const Vec3 position_);
		~camera();

		float aspectRatio;
		camera* currentCamera;

		//Matrix Methods
		void UpdateViewMatrix();
		Matrix4&  getProjectionMatrix();
		Matrix4&  getViewMatrix();

		//Set Camera Movement Components
		void setPosition(const Vec3& position_);
		void setRotation(const Vec3& rotation_);
		void setUpDirection(const Vec3& dir_);

		/// Return the 4x4 rotational matrix
		Matrix4 GetMatrix4() const { return viewMatrix; }

		/// Return the 3x3 rotational matrix, rotational matrix is a 3x3
		Matrix3 GetMatrix3() const { return Matrix3(viewMatrix); }

	};
}



#endif