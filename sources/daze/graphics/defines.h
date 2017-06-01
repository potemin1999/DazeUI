#ifndef GRAPHICS_DEFINES_H_INCLUDED
#define GRAPHICS_DEFINES_H_INCLUDED

#ifdef DEBUG
#define DEBUG_TEXTURE
#define DEBUG_SURFACE
#endif // DEBUG

#if ( defined(_WIN32) | defined(__WIN32) | defined(__linux__) )

#include "glad/glad.h"
#include "khr/khrplatform.h"

#elif ( defined(_ANDROID_) )

#endif

namespace daze{
class Texture;
class Framebuffer;
class Shader;
}

#endif // GRAPHICS_DEFINES_H_INCLUDED
