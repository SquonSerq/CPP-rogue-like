#pragma once

#include "lib/ecs/component.h"

class ColorComponent : public IComponent {
 public:
  uint8_t alpha_;
  uint8_t red_;
  uint8_t green_;
  uint8_t blue_;

  explicit ColorComponent(uint8_t alpha, uint8_t red, uint8_t green, int8_t blue)
      : alpha_(alpha), red_(red), green_(green), blue_(blue) {}
};
