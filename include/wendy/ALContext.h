///////////////////////////////////////////////////////////////////////
// Wendy OpenAL library
// Copyright (c) 2007 Camilla Berglund <elmindreda@elmindreda.org>
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
#ifndef WENDY_ALCONTEXT_H
#define WENDY_ALCONTEXT_H
///////////////////////////////////////////////////////////////////////

#include <wendy/Core.h>
#include <wendy/Path.h>
#include <wendy/Resource.h>

///////////////////////////////////////////////////////////////////////

namespace wendy
{
  namespace AL
  {

///////////////////////////////////////////////////////////////////////

/*! @ingroup openal
 */
class Context : public Singleton<Context>
{
public:
  ~Context(void);
  const vec3& getListenerPosition(void) const;
  void setListenerPosition(const vec3& newPosition);
  const vec3& getListenerVelocity(void) const;
  void setListenerVelocity(const vec3& newVelocity);
  float getListenerGain(void) const;
  void setListenerGain(float newGain);
  ResourceIndex& getIndex(void) const;
  static bool createSingleton(ResourceIndex& index);
private:
  Context(ResourceIndex& index);
  Context(const Context& source);
  bool init(void);
  Context& operator = (const Context& source);
  ResourceIndex& index;
  void* device;
  void* context;
  vec3 listenerPosition;
  vec3 listenerVelocity;
  float listenerGain;
};

///////////////////////////////////////////////////////////////////////

  } /*namespace AL*/
} /*namespace wendy*/

///////////////////////////////////////////////////////////////////////
#endif /*WENDY_ALCONTEXT_H*/
///////////////////////////////////////////////////////////////////////
