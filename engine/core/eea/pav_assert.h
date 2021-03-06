#ifndef PAV_ASSERT_H
#define PAV_ASSERT_H

#include <assert.h>

#ifndef ASSERT_REASON
#define PRECOMPILED_ENGINE_SETTING_UNDEFINED "One or more precompiled settings are not defined!"
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