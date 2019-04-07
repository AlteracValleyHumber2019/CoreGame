#ifndef PAV_ASSERT_H
#define PAV_ASSERT_H

#include <assert.h>

#ifndef ASSERT_REASON
// MSIC
#define CSTR_CONCAT(a,b) a ## b

// General engine
#define PRECOMPILED_ENGINE_SETTING_UNDEFINED "One or more precompiled settings are not defined!"

// Graphics
#define SHADER_UNIFORM_LOCATION_UNDEFINED(location) CSTR_CONCAT("One or more precompiled settings are not defined! Location: ", #location)

#define SHADER_COMPILE_FAILED_IMPL1 "Shader compile failed! \n Shader type:"
#define SHADER_COMPILE_FAILED_IMPL2 "\nReason: "
#define SHADER_COMPILE_FAILED(type, reason) SHADER_COMPILE_FAILED_IMPL1 #type SHADER_COMPILE_FAILED_IMPL2 #reason

#define SHADER_LINKING_FAILED(reason) "Shader linking failed! Reason: " #reason

#define INVALID_SHADER "The shader you are attempting to use is most likely been deleted or not created."

#define INVALID_SHADER_PROGRAM "The shader program you are attempting to use is most likely been deleted or not created."
#endif

#ifdef _DEBUG

#define PAV_ASSERT(condition, msg)							\
{															\
	assert((msg, condition));								\
}															\

#define PAV_WARNING(condition, msg)							\
{															\
	if (condition)											\
	{														\
		pav::PAVAssert::PrintFileLine(__FILE__, __LINE__);	\
		printf("WARNING: %s\n", msg);						\
	}														\
}															\

#else
#define PAV_ASSERT(condition, msg)
#endif

namespace pav
{
	class PAVAssert
	{
	public:
		inline static void PrintFileLine(const char* file_name, const int line)
		{
			printf("File: %s, Line: %d\n", file_name, line);
		}
	};
}

#endif // PAV_ASSERT_H