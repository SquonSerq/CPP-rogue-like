#pragma once

#include <lib/ecs/component.h>

class SystemPlayComponent : public IComponent {
 public:
  bool editor_;

  explicit SystemPlayComponent(bool editor) : editor_(editor) {}
};
