#ifndef AV_OBJECT_H
#define AV_OBJECT_H

#include "pav_pch.h"
#include "objLoader.h"
#include <vector>

using namespace pav;

class AV_object {

private:

	std::vector<std::shared_ptr<Mesh>> meshes; 
	std::shared_ptr<Shader> shader;

	std::string directory;

	glm::mat4 modelMatrix;

	int projectionMatrixID;
	int modelViewMatrixID;
	int normalMatrixID;

	uint16_t vbo;
	uint16_t vao;

public:

	AV_object(const AV_object&) = delete;
	AV_object(AV_object&&) = delete;
	AV_object& operator = (const AV_object&) = delete;
	AV_object& operator = (AV_object&&) = delete;

	AV_object(std::string filename_);
	AV_object(std::vector<std::shared_ptr<Mesh>> mesh_);
	virtual ~AV_object();

	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Render(const glm::mat4& projectionMatrix, const glm::mat4& modelViewMatrix, const glm::mat3& normalMatrix)const;


	//Getters
	inline std::vector<std::shared_ptr<Mesh>> getMesh() const { return meshes; }
	inline std::shared_ptr<Shader> getShader() const { return shader; }
	inline std::string getDirectory() const { return directory; }

	inline int getProjectionMatrixID() const { return projectionMatrixID; }
	inline int getModelViewMatrixID() const { return modelViewMatrixID; }
	inline int getNormalMatrixID() const { return normalMatrixID; }

	inline uint16_t getVBO() const { return vbo; }
	inline uint16_t getVAO() const { return vao; }

};

#endif

