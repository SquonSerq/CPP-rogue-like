#pragma once

#include "game/utils/IRender.h"

class SceneRenderer : public IRender {
 public:
  SceneRenderer() = default;

  void Render(Entity *entity) override;
};
