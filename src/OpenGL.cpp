///////////////////////////////////////////////////////////////////////
// Wendy OpenGL library
// Copyright (c) 2010 Camilla Berglund <elmindreda@elmindreda.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any
// damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any
// purpose, including commercial applications, and to alter it and
// redistribute it freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you
//     must not claim that you wrote the original software. If you use
//     this software in a product, an acknowledgment in the product
//     documentation would be appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and
//     must not be misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source
//     distribution.
//
///////////////////////////////////////////////////////////////////////

#include <wendy/Config.h>
#include <wendy/Core.h>

#include <wendy/OpenGL.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <Cg/cg.h>
#include <Cg/cgGL.h>

#include <cstdlib>
#include <cstdio>

///////////////////////////////////////////////////////////////////////

namespace wendy
{
  namespace GL
  {

///////////////////////////////////////////////////////////////////////

bool checkGL(const char* format, ...)
{
  GLenum error = glGetError();
  if (error == GL_NO_ERROR)
    return true;

  va_list vl;
  char* message;
  int result;

  va_start(vl, format);
  result = vasprintf(&message, format, vl);
  va_end(vl);

  if (result < 0)
  {
    Log::writeError("Error formatting error message for OpenGL error %u", error);
    return false;
  }

  Log::writeError("%s: %s", message, gluErrorString(error));

  std::free(message);
  return false;
}

bool checkCg(const char* format, ...)
{
  CGerror error = cgGetError();
  if (error == CG_NO_ERROR)
    return true;

  va_list vl;
  char* message;
  int result;

  va_start(vl, format);
  result = vasprintf(&message, format, vl);
  va_end(vl);

  if (result < 0)
  {
    Log::writeError("Error formatting error message for Cg error %u", error);
    return false;
  }

  Log::writeError("%s: %s", message, cgGetErrorString(error));

  std::free(message);
  return false;
}

///////////////////////////////////////////////////////////////////////

  } /*namespace GL*/
} /*namespace wendy*/

///////////////////////////////////////////////////////////////////////