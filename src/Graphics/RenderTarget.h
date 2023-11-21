#ifndef ___RENDERTARGET_H___
#define ___RENDERTARGET_H___

#include "Plug/Graphics/RenderTarget.h"
using plug::RenderTarget;
#include "Graphics/Graphics.h"

/**
 * @brief Framebuffer object with single color attachment (as texture) and
 * depth-stencil buffer (as RenderBuffer) (just use it as a window wrapper, both
 * SFML and SDL will perform all the required magic by themselves)
 *
 */
class SFMLRenderTarget : public plug::RenderTarget {
public:
  /**
   * @brief Draw vertex array with specified vertex colors
   *
   * @param array
   */
  virtual void draw(const VertexArray& array) override;

  /**
   * @brief Draw vertex array with texture-based coloring
   *
   * @param array
   * @param texture
   */
  virtual void draw(const VertexArray& array, const Texture& texture) override;

  /**
   * @brief Fill color attachment with specified color and reset depth and
   * stencil buffers
   *
   * @param color
   */
  virtual void clear(Color color) override;

  /**
   * @brief Get OpenGL identifier of the related framebuffer
   *
   * @return unsigned
   */
  unsigned getNativeHandle(void) const;
};

#endif // ___RENDERTARGET_H___