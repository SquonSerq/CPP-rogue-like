#include "game/scenes/LevelStats.h"

#include <game/components/PlayerControlComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/RenderingSystem.h>
#include <game/utils/LevelStatsRenderer.h>

#include <vector>

LevelStats::LevelStats(Context *ctx, const Controls &controls, const Engine &engine)
    : IScene(ctx), controls_(controls), engine_(engine) {}

void LevelStats::OnCreate() {
  engine_.GetSystemManager()->DeleteAll();
  for (auto &e : *engine_.GetEntityManager()) {
    if (e.Contains<TransformComponent>()) {
      e.Delete<TransformComponent>();
    }

    if (e.Contains<PlayerControlComponent>()) {
      e.Get<PlayerControlComponent>()->isMovable = false;
    }
  }

  std::vector<IRender *> renders;
  renders.push_back(new LevelStatsRenderer);

  auto sys = engine_.GetSystemManager();

  sys->AddSystem<RenderingSystem>(renders);
}

void LevelStats::OnRender() {
  if (controls_.IsPressed(TK_SPACE)) {
    ctx_->scene_ = "FirstFloor";
  }
  engine_.OnUpdate();
}

void LevelStats::OnExit() {
  engine_.GetSystemManager()->DeleteAll();
  engine_.GetEntityManager()->DeleteAll();
}
