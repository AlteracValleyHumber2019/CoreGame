#ifndef I_SHADER_RESOURCE_H
#define I_SHADER_RESOURCE_H

#include "core/resource_system/resource.h"
#include "core/graphics/i_shader_program.h"

namespace pav
{
	class IShaderResource : public Resource<IShaderResource, IShaderProgram*, std::string>
	{
	public:
	};
}

#endif // I_SHADER_RESOURCE_H