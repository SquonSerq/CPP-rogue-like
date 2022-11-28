#pragma once

#include <Controls.h>
#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>

class FirstFloor : public IScene {
  const Controls &controls_;
  const Engine &engine_;

 public:
  FirstFloor(Context *ctx, const Controls &controls, const Engine &engine);

  void OnCreate() override;

  void OnRender() override;

  void OnExit() override;
};
