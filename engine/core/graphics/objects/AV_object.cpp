#include "pav_pch.h"
#include "AV_object.h"
#include <gl\GL.h>

AV_object::AV_object(std::string filename_) {
	ObjLoader obj(filename_.c_str());
	directory = filename_;
	meshes.push_back(std::shared_ptr<Mesh>(new Mesh(GL_TRIANGLES, obj.vertices, obj.normals, obj.uvCoords)));
	OnCreate();
}

AV_object::AV_object(std::vector<std::shared_ptr<Mesh>> mesh_) {
	meshes = mesh_;
	OnCreate();
}

AV_object::~AV_object() {
	OnDestroy();
}

bool AV_object::OnCreate() {
	shader = std::shared_ptr<Shader>(new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords"));
	projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
	modelViewMatrixID = glGetUniformLocation(shader->getProgram(), "modelViewMatrix");
	normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");

	return true;
}

void AV_object::OnDestroy() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void AV_object::Render(const Matrix4& projectionMatrix, const Matrix4& modelViewMatrix, const Matrix3& normalMatrix)const {

}