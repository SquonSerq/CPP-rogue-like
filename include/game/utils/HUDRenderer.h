#pragma once

#include "game/utils/IRender.h"

class HUDRenderer : public IRender {
 public:
  HUDRenderer();

  void Render(Entity *entity) override;
};
