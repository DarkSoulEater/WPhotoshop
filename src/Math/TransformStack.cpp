#include "TransformStack.h"
#include <assert.h>

TransformStack::TransformStack() {
    stack_trm_.push(Transform());
}

void TransformStack::enter(const Transform &transform) {
    Transform transform_(stack_trm_.top());
    transform_.combine(transform);
    stack_trm_.push(transform_);
}

void TransformStack::leave() {
    assert(stack_trm_.size() > 1);
    if (stack_trm_.size() > 1) stack_trm_.pop();
}

Transform TransformStack::top() const {
    return stack_trm_.top();
}

Vec2d TransformStack::apply(const Vec2d &vec) const {
    return stack_trm_.top().apply(vec);
}

Vec2d TransformStack::restore(const Vec2d &vec) const {
    return stack_trm_.top().restore(vec);
}
