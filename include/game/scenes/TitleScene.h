#pragma once

#include <Controls.h>
#include <lib/scenes/i_scene.h>
#include <lib/ecs/engine.h>

class TitleScene : public IScene {
  const Controls &controls_;
  const Engine &engine_;
  int menuPos = 1;

 public:
  TitleScene(Context *ctx, const Controls &controls, const Engine &engine);

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};
