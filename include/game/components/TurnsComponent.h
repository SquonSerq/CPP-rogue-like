#pragma once

#include "lib/ecs/component.h"

class TurnsComponent : public IComponent {
 public:
  int currentTurns_;
  int turnsLimit_;
  bool isTurn = false;

  explicit TurnsComponent(int turns, int turnsLimit) : currentTurns_(turns), turnsLimit_(turnsLimit) {}
};
