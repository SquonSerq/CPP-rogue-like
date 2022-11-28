#pragma once

#include <lib/ecs/entity.h>

class IRender {
 public:
  virtual void Render(Entity *entity) {}
};
