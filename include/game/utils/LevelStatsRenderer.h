#pragma once

#include "game/utils/IRender.h"

class LevelStatsRenderer : public IRender {
 public:
  void Render(Entity *entity) override;
};
