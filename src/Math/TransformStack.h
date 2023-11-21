#ifndef ___TRANSFORMSTACK_H___
#define ___TRANSFORMSTACK_H___

#include "stack"
#include "Plug/Math/TransformStack.h"
#include "Math/Math.h"

class TransformStack : public plug::TransformStack {
public:
    TransformStack();

  /**
   * \brief Enter a transform to the top of the stack and pushes the new
   * transform onto the top of the stack
   */
  virtual void enter(const Transform& transform) override;

  /**
   * \brief Removes a transform from the top of the stack
   */
  virtual void leave() override;

  /**
   * \brief Gets stack top transform
   */
  virtual Transform top() const override;

  /**
   * \brief Converts local position to on-screen position using top transform
   */
  virtual Vec2d apply(const Vec2d& vec) const override;

  /**
   * \brief Converts on-screen position to local position using top transform
   */
  virtual Vec2d restore(const Vec2d& vec) const override;

private:
    std::stack<Transform> stack_trm_;
};

#endif // ___TRANSFORMSTACK_H___