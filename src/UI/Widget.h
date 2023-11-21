#ifndef ___WIDGET_H___
#define ___WIDGET_H___

#include "Plug/Widget.h"
#include "Core/Event.h"
#include "Math/Math.h"
#include "Graphics/Graphics.h"
#include "UI/LayoutBox/LayoutBox.h"

class Widget : public plug::Widget {
public:
  /**
   * @brief Draw widget
   *
   * @param stack
   * @param target buffer which the widget will be drawn on
   */
  virtual void draw(TransformStack& stack, RenderTarget& target) override;

  /**
   * @brief Handle abstract event
   *
   * @param event
   * @param context event handling context
   */
  virtual void onEvent(const Event& event, EHC& context) override;

  /**
   * @brief Update widget according to the parent
   *
   * @param parent_box parent layout box
   */
  virtual void onParentUpdate(const LayoutBox& parent_box) override;

  virtual LayoutBox&       getLayoutBox() override;
  virtual const LayoutBox& getLayoutBox() const override;
  virtual void             setLayoutBox(const LayoutBox& box) override;
};

#endif // ___WIDGET_H___