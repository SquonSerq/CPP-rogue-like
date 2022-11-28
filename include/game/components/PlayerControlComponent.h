#pragma once

#include <lib/ecs/component.h>

class PlayerControlComponent : public IComponent {
 public:
  int up_button_;
  int down_button_;
  int left_button_;
  int right_button;
  bool isMovable = true;

  explicit PlayerControlComponent(int up_button, int down_button, int left_button, int right_button)
      : up_button_(up_button), down_button_(down_button), left_button_(left_button), right_button(right_button) {}
};
