#pragma once

#include "lib/ecs/component.h"

class InventoryComponent : public IComponent {
 public:
  int coins_;

  explicit InventoryComponent(int coins) : coins_(coins) {}
};
