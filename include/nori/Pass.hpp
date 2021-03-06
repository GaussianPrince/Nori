///////////////////////////////////////////////////////////////////////
// Nori - a simple game engine
// Copyright (c) 2011 Camilla Berglund <elmindreda@elmindreda.org>
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

#include <nori/Core.hpp>

#include <nori/Texture.hpp>
#include <nori/RenderBuffer.hpp>
#include <nori/Program.hpp>
#include <nori/RenderContext.hpp>

#include <cstring>

namespace nori
{

class RenderSystem;

typedef uint16 PassID;

/*! @brief Opaque program state uniform index.
 */
class UniformStateIndex
{
  friend class Pass;
public:
  UniformStateIndex();
private:
  UniformStateIndex(uint16 index, uint16 offset);
  uint16 index;
  uint16 offset;
};

/*! @brief Render state object.
 *
 *  This class and its associated classes encapsulates most rendering state.
 *
 *  @remarks Yes, it's big.
 */
class Pass
{
public:
  /*! Constructor.
   */
  Pass();
  Pass(const Pass& source);
  ~Pass();
  /*! Applies this render state to the current context.
   */
  void apply() const;
  Pass& operator = (const Pass& source);
  /*! @return @c true if this render state uses any form of culling, otherwise
   *  @c false.
   */
  bool isCulling() const;
  /*! @return @c true if this render state uses any form of blending with the
   *  framebuffer, otherwise @c false.
   */
  bool isBlending() const;
  /*! @return @c true if this render state uses depth buffer testing, otherwise
   *  @c false.
   */
  bool isDepthTesting() const;
  /*! @return @c true if this render state writes to the depth buffer, otherwise
   *  @c false.
   */
  bool isDepthWriting() const;
  /*! @return @c true if this render state writes to the color buffer, otherwise
   *  @c false.
   */
  bool isColorWriting() const;
  /*! @return @c true if this render state uses stencil buffer testing,
   *  otherwise @c false.
   */
  bool isStencilTesting() const;
  /*! @return @c true if this render state uses wireframe rendering, otherwise
   *  @c false.
   */
  bool isWireframe() const;
  /*! @return @c true if this render state uses line smoothing, otherwise @c false.
   */
  bool isLineSmoothing() const;
  /*! @return @c true if this render state uses multisampling, otherwise @c false.
   */
  bool isMultisampling() const;
  /*! @return @c the width of lines, in pixels.
   */
  float lineWidth() const;
  /*! @return The polygon faces to be culled by this render state.
   */
  PolygonFace cullFace() const;
  /*! @return The source factor for color buffer blending.
   */
  BlendFactor srcFactor() const;
  /*! @return The destination factor for color buffer blending.
   */
  BlendFactor dstFactor() const;
  /*! @return The depth buffer testing function used by this render state.
   */
  FragmentFunction depthFunction() const;
  /*! @return The stencil buffer testing function used by this render state.
   */
  FragmentFunction stencilFunction(PolygonFace face) const;
  /*! @return The operation to perform when the stencil test fails.
   */
  StencilOp stencilFailOperation(PolygonFace face) const;
  /*! @return The operation to perform when the depth test fails.
   */
  StencilOp depthFailOperation(PolygonFace face) const;
  /*! @return The operation to perform when the depth test succeeds.
   */
  StencilOp depthPassOperation(PolygonFace face) const;
  /*! @return The stencil test reference value used by this render state.
   */
  uint stencilReference(PolygonFace face) const;
  /*! @return The stencil buffer write mask used by this render state.
   */
  uint stencilWriteMask(PolygonFace face) const;
  /*! Sets whether this render state uses depth buffer testing.
   *  @param[in] enable Set to @c true to enable depth buffer testing, or @c
   *  false to disable it.
   */
  void setDepthTesting(bool enable);
  /*! Sets whether this render state writes to the depth buffer.
   *  @param[in] enable Set to @c true to enable depth buffer writing, or @c
   *  false to disable it.
   */
  void setDepthWriting(bool enable);
  /*! Sets whether this render state uses stencil buffer testing.
   *  @param[in] enable Set to @c true to enable stencil buffer testing, or @c
   *  false to disable it.
   */
  void setStencilTesting(bool enable);
  /*! Sets the depth buffer testing function for this render state.
   *  @param[in] function The desired depth testing function.
   */
  void setDepthFunction(FragmentFunction function);
  /*! Sets the stencil test function for this render state.
   *  @param[in] newFunction The desired stencil testing function.
   */
  void setStencilFunction(PolygonFace face, FragmentFunction newFunction);
  /*! Sets the stencil test reference value for this render state.
   *  @param[in] newReference The desired stencil test reference value.
   */
  void setStencilReference(PolygonFace face, uint newReference);
  /*! Sets the stencil buffer write mask for this render state.
   *  @param[in] newMask The desired stencil buffer write mask.
   */
  void setStencilWriteMask(PolygonFace face, uint newMask);
  /*! Sets the operation to perform when the stencil test fails.
   */
  void setStencilFailOperation(PolygonFace face, StencilOp newOperation);
  /*! Sets the operation to perform when the depth test fails.
   */
  void setDepthFailOperation(PolygonFace face, StencilOp newOperation);
  /*! Sets the operation to perform when the depth test succeeds.
   */
  void setDepthPassOperation(PolygonFace face, StencilOp newOperation);
  /*! Sets whether writing to the color buffer is enabled.
   *  @param[in] enabled @c true to enable writing to the color buffer, or @c
   *  false to disable it.
   */
  void setColorWriting(bool enabled);
  /*! Sets whether wireframe rendering is enabled.
   *  @param[in] enabled @c true to enable wireframe rendering, or @c false to
   *  disable it.
   */
  void setWireframe(bool enabled);
  /*! Sets whether line smoothing is enabled.
   *  @param[in] enabled @c true to enable line smoothing, or @c false to disable it.
   */
  void setLineSmoothing(bool enabled);
  /*! Sets whether multisampling is enabled.
   *  @param[in] enabled @c true to enable multisampling, or @c false to disable it.
   */
  void setMultisampling(bool enabled);
  /*! Sets the width of lines, in pixels.
   *  @param[in] newWidth The desired new line width.
   */
  void setLineWidth(float newWidth);
  /*! Sets the specified polygon faces to be culled.
   *  @param[in] face The desired faces to be culled.
   */
  void setCullFace(PolygonFace face);
  /*! Sets the factors for color buffer blending.
   *  @param[in] src The desired source factor.
   *  @param[in] dst The desired destination factor.
   */
  void setBlendFactors(BlendFactor src, BlendFactor dst);
  bool hasUniformState(const char* name) const;
  template <typename T>
  T uniformState(const char* name) const
  {
    return uniformState<T>(uniformStateIndex(name));
  }
  template <typename T>
  T uniformState(UniformStateIndex index) const
  {
    return *static_cast<const T*>(data(index, uniformType<T>()));
  }
  template <typename T>
  void setUniformState(const char* name, const T& value)
  {
    setUniformState(uniformStateIndex(name), value);
  }
  template <typename T>
  void setUniformState(UniformStateIndex index, const T& value)
  {
    *static_cast<T*>(data(index, uniformType<T>())) = value;
  }
  Texture* uniformTexture(const char* name) const;
  Texture* uniformTexture(UniformStateIndex index) const;
  void setUniformTexture(const char* name, Texture* texture);
  void setUniformTexture(UniformStateIndex index, Texture* texture);
  UniformStateIndex uniformStateIndex(const char* name) const;
  Program* program() const { return m_program; }
  /*! Sets the GLSL program used by this state object.
   *  @param[in] newProgram The desired GLSL program, or @c nullptr to detach
   *  the current program.
   */
  void setProgram(Program* program);
  PassID id() const { return m_id; }
private:
  template <typename T>
  static UniformType uniformType();
  void* data(UniformStateIndex index, UniformType type);
  const void* data(UniformStateIndex index, UniformType type) const;
  PassID m_id;
  Ref<Program> m_program;
  std::vector<char> m_uniformState;
  RenderState m_state;
};

} /*namespace nori*/

