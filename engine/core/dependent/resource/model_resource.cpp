#include "pav_pch.h"
#include "model_resource.h"

pav::Model pav::ModelResource::GetData()
{
	return resource;
}

bool pav::ModelResource::Load(std::string&& args, ModelLoadInfo&& info)
{
	Assimp::Importer assimp_importer;

	const aiScene* assimp_scene = assimp_importer.ReadFile
	(
		args,
		aiProcess_Triangulate |
		aiProcess_FlipUVs |
		aiProcess_GenNormals
	);

	// If the import failed, report it
	if (!assimp_scene)
	{
		PAV_ASSERT(false, (assimp_importer.GetErrorString()));
		return false;
	}

	ProcessScene(assimp_scene, assimp_scene->mRootNode);

	return true;
}

void pav::ModelResource::ProcessScene(const aiScene* scene, aiNode* node)
{
	// Load all meshes in node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* current_mesh = scene->mMeshes[node->mMeshes[i]];
		auto mesh = CalcMesh(scene, current_mesh);

		resource.meshes.push_back(mesh);
	}

	// Load all its sub meshes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessScene(scene, node->mChildren[i]);
	}
}

pav::Mesh pav::ModelResource::CalcMesh(const aiScene* scene, aiMesh* mesh)
{
	Mesh pav_mesh;

	// Load all position and texture positions
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex ver;

		// Load position
		const auto pos = mesh->mVertices[i];
		ver.position.x = pos.x;
		ver.position.y = pos.y;
		ver.position.z = pos.z;

		// Load normals
		if (mesh->mNormals != nullptr)
		{
			const auto n_pos = mesh->mNormals[i];
			ver.normal.x = n_pos.x;
			ver.normal.y = n_pos.y;
			ver.normal.z = n_pos.z;
		}

		if (mesh->mTextureCoords[0]) // If there is texture cord in first index
		{
			const auto tex = mesh->mTextureCoords[0][i];
			ver.texture_position = glm::vec2(tex.x, tex.y);
		}
		else
		{
			ver.texture_position = glm::vec2(0.f, 0.f);
		}

		pav_mesh.vertices.push_back(ver);
	}

	// Indices
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		const auto face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			pav_mesh.indices.push_back(face.mIndices[j]);
	}

	return pav_mesh;
}

pav::Model pav::ModelResource::GetData() const
{
	return resource;
}
