#include "core/resource_system/resource.h"
#include "core/graphics/model.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#ifndef MODEL_RESOURCE_H
#define MODEL_RESOURCE_H

namespace pav
{
	struct ModelLoadInfo
	{
		enum ModelFormatType
		{
			OBJ,
			FBX
		};

		ModelFormatType ModelFormat;
	};

	class ModelResource : public Resource<ModelResource, Model, std::string, ModelLoadInfo>
	{
	public:

		virtual Model GetData() override;


		virtual Model GetData() const override;


		virtual bool Load(std::string&& args, ModelLoadInfo&& info) override;

	private:
		Model resource;

		void ProcessScene(const aiScene* scene, aiNode* node);

		Mesh CalcMesh(const aiScene* scene, aiMesh* mesh);
	};
}
#endif // MODEL_RESOURCE_H