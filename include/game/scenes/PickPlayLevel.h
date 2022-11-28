#pragma once

#include <Controls.h>
#include <game/scenes/FirstFloor.h>
#include <lib/ecs/engine.h>

class PickPlayLevel : public IScene {
  const Controls &controls_;
  const Engine &engine_;
  ulong menuPos_ = 0;

 public:
  PickPlayLevel(Context *ctx, const Controls &controls, const Engine &engine);

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};
