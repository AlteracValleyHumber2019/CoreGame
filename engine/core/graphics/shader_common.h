#ifndef SHADER_COMMON_H
#define SHADER_COMMON_H

namespace pav
{

#define SHADER_TYPE_COUNT 4

	/**
	 * \enum	ShaderType
	 *
	 * \brief	Values that represent common shader types
	 */
	enum class ShaderType
	{
		VERTEX_SHADER = 0,
		TESSELLATION_SHADER = 1,
		GEOMETRY_SHADER = 2,
		FRAGMENT_SHADER = 3
	};

}

#endif // SHADER_COMMON_H
