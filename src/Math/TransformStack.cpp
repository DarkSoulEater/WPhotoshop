#include "TransformStack.h"
#include <assert.h>

WTransformStack::WTransformStack() {
    stack_trm_.push(Transform());
}

void WTransformStack::enter(const Transform &transform) {
    Transform transform_(stack_trm_.top());
    transform_.combine(transform);
    stack_trm_.push(transform_);
}

void WTransformStack::leave() {
    assert(stack_trm_.size() > 1);
    if (stack_trm_.size() > 1) stack_trm_.pop();
}

Transform WTransformStack::top() const {
    return stack_trm_.top();
}

Vec2d WTransformStack::apply(const Vec2d &vec) const {
    return stack_trm_.top().apply(vec);
}

Vec2d WTransformStack::restore(const Vec2d &vec) const {
    return stack_trm_.top().restore(vec);
}
