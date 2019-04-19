#ifndef TYPE_WRAPPERS_H
#define TYPE_WRAPPERS_H

#ifdef ENGINE_TYPE_GL_SDL

#include <glad/glad.h>
#include <SDL/SDL.h>
using GAPIUInt = GLuint;
using WindowType = SDL_Window;

#else

using GAPIUInt = unsigned int;
using WindowType = unsigned int;

#endif

#endif // TYPE_WRAPPERS_H
