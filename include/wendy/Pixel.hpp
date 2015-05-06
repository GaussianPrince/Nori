///////////////////////////////////////////////////////////////////////
// Nori - a simple game engine
// Copyright (c) 2009 Camilla Berglund <elmindreda@elmindreda.org>
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

#pragma once

namespace nori
{

/*! @brief %Pixel format descriptor.
 *
 *  All formats are at least byte aligned, although their channels may not be.
 */
class PixelFormat
{
public:
  /*! Pixel format semantic enumeration.
   */
  enum Semantic
  {
    NONE,
    L,
    LA,
    RGB,
    RGBA,
    DEPTH
  };
  /*! Pixel format component type enumeration.
   */
  enum Type
  {
    DUMMY,
    UINT8,
    UINT16,
    UINT24,
    UINT32,
    FLOAT16,
    FLOAT32
  };
  /*! Default constructor.
   *  @param[in] semantic The desired semantic of this pixel format.
   *  @param[in] type The desired type of this pixel format.
   */
  PixelFormat(Semantic semantic = NONE, Type type = DUMMY);
  /*! Constructor. Creates components according to the specified specification.
   *  @param specification The specification of the desired format.
   *  @remarks This will throw if the specification is syntactically malformed.
   */
  explicit PixelFormat(const char* specification);
  /*! @return @c true if the pixel formats are equal, @c false otherwise.
   */
  bool operator == (const PixelFormat& other) const;
  /*! @return @c true if the pixel formats are not equal, @c false otherwise.
   */
  bool operator != (const PixelFormat& other) const;
  /*! @return @c true if this pixel format describes to a physical pixel
   *  format.
   */
  bool isValid() const { return m_semantic != NONE && m_type != DUMMY; }
  /*! @return The size, in bytes, of a pixel in this pixel format.
   */
  size_t size() const { return channelSize() * channelCount(); }
  /*! @return The size, in bytes, of a channel of a pixel in this pixel format.
   */
  size_t channelSize() const;
  /*! @return The channel data type of this pixel format.
   */
  Type type() const { return m_type; }
  /*! @return The channel semantic of this pixel format.
   */
  Semantic semantic() const { return m_semantic; }
  /*! @return The number of components in this pixel format.
   */
  uint channelCount() const;
  /*! @return A string representation of this pixel format.
   */
  static const PixelFormat L8;
  static const PixelFormat L16;
  static const PixelFormat L16F;
  static const PixelFormat L32F;
  static const PixelFormat LA8;
  static const PixelFormat LA16;
  static const PixelFormat LA16F;
  static const PixelFormat LA32F;
  static const PixelFormat RGB8;
  static const PixelFormat RGB16;
  static const PixelFormat RGB16F;
  static const PixelFormat RGB32F;
  static const PixelFormat RGBA8;
  static const PixelFormat RGBA16;
  static const PixelFormat RGBA16F;
  static const PixelFormat RGBA32F;
  static const PixelFormat DEPTH16;
  static const PixelFormat DEPTH24;
  static const PixelFormat DEPTH32;
  static const PixelFormat DEPTH16F;
  static const PixelFormat DEPTH32F;
private:
  Semantic m_semantic;
  Type m_type;
};

const char* stringCast(PixelFormat::Semantic semantic);
const char* stringCast(PixelFormat::Type type);
std::string stringCast(PixelFormat format);

} /*namespace nori*/

