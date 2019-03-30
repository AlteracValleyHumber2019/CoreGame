#ifndef GL_VAO_RESOURCE_H
#define GL_VAO_RESOURCE_H

#include "core/resource_system/resource.h"

namespace pav
{
	class GLVAOResource : public pav::Resource<GLVAOResource, int>
	{
	public:
		virtual int GetData() override;

		virtual int GetData() const override;

		virtual bool Load(void) override;

	};
}

#endif // GL_VAO_RESOURCE_H