#include "game/systems/TurnsSystem.h"

#include <game/components/TurnsComponent.h>

TurnsSystem::TurnsSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx)
    : ISystem(entityManager, systemManager), ctx_(ctx) {}

void TurnsSystem::OnUpdate() {
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<TurnsComponent>()) {
      auto tc = entity.Get<TurnsComponent>();

      if (tc->isTurn) {
        entity.Get<TurnsComponent>()->currentTurns_ += 1;

        if (tc->currentTurns_ >= tc->turnsLimit_) {
            ctx_->scene_ = "GameOver";
        }
      }
    }
    break;
  }
}
