#ifndef OBJLOADER_H
#define OBJLOADER_H
#include "pav_pch.h"
#include <vector>
#include "objLoader.h"
#include "ScottVector.h"

using namespace pav;
using namespace MATH;

	class ObjLoader {
	public:
		std::vector<Vec3> vertices;
		std::vector<Vec2>  uvCoords;
		std::vector<Vec3>  normals;

		/// C11 precautions 
		ObjLoader(const ObjLoader&) = delete;  /// Copy constructor
		ObjLoader(ObjLoader&&) = delete;       /// Copy operator
		ObjLoader& operator=(const ObjLoader&) = delete; /// Move constructor
		ObjLoader& operator=(ObjLoader&&) = delete;      /// Move operator

		ObjLoader(const char* path);
		bool loadOBJ(const char* path);
	private:


	};
#endif