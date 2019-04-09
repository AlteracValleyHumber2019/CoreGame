#include "core/resource_system/resource.h"
#include "core/graphics/model.h"

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

	};
}