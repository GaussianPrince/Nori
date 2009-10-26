///////////////////////////////////////////////////////////////////////
// Wendy default renderer
// Copyright (c) 2006 Camilla Berglund <elmindreda@elmindreda.org>
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
#ifndef WENDY_RENDERIO_H
#define WENDY_RENDERIO_H
///////////////////////////////////////////////////////////////////////

namespace wendy
{
  namespace render
  {

///////////////////////////////////////////////////////////////////////

using namespace moira;

///////////////////////////////////////////////////////////////////////

/*! @brief Codec for XML format render materials.
 *  @ingroup io
 */
class MaterialCodec : ResourceCodec<Material>, public XML::Codec
{
public:
  MaterialCodec(void);
  Material* read(const Path& path, const String& name = "");
  Material* read(Stream& stream, const String& name = "");
  bool write(const Path& path, const Material& material);
  bool write(Stream& stream, const Material& material);
private:
  bool onBeginElement(const String& name);
  bool onEndElement(const String& name);
  Ptr<Material> material;
  Technique* currentTechnique;
  Pass* currentPass;
  String materialName;
};

///////////////////////////////////////////////////////////////////////

  } /*namespace render*/
} /*namespace wendy*/

///////////////////////////////////////////////////////////////////////
#endif /*WENDY_RENDERIO_H*/
///////////////////////////////////////////////////////////////////////
