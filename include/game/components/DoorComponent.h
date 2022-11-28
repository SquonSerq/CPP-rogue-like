#pragma once

#include <string>

#include "lib/ecs/component.h"

class DoorComponent : public IComponent {
 public:
  std::string nextScene_;

  explicit DoorComponent(std::string nextScene) : nextScene_(nextScene) {}
};
