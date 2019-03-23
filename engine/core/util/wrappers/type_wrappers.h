#ifndef TYPE_WRAPPERS_H
#define TYPE_WRAPPERS_H

#ifdef ENGINE_TYPE_GL_SDL

#include <glad/glad.h>
using GAPIUInt = GLuint;

#else

using GAPIUInt = unsigned int;

#endif

#endif // TYPE_WRAPPERS_H
