#include "game/systems/BattleSystem.h"

#include <game/components/BattleComponent.h>
#include <game/components/HealthComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TurnsComponent.h>

#include <vector>

BattleSystem::BattleSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx)
    : ISystem(entityManager, systemManager), ctx_(ctx) {}

void BattleSystem::OnUpdate() {
  bool madeTurn = true;
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<TurnsComponent>()) {
      madeTurn = entity.Get<TurnsComponent>()->isTurn;
      break;
    }
  }

  std::vector<Entity *> deleteEntities;

  if (madeTurn) {
    for (auto &movEnt : *GetEntityManager().GetByTag("MovementSystem")) {
      if (movEnt->Get<MovementComponent>()->AnyObstacles() && movEnt->Contains<BattleComponent>()) {
        auto mc = movEnt->Get<MovementComponent>();
        for (auto enemy : mc->GetObstacles()) {
          if (enemy->GetId() == movEnt->GetId()) {
            mc->DeleteObstacle(enemy->GetId());
            continue;
          }

          if (enemy->Contains<HealthComponent>() && enemy->Contains<BattleComponent>()) {
            enemy->Get<HealthComponent>()->health_ -= movEnt->Get<BattleComponent>()->damage_;

            if (enemy->Get<HealthComponent>()->health_ <= 0) {
              if (enemy->Contains<PlayerControlComponent>()) {
                ctx_->scene_ = "GameOver";
                break;
              }
              deleteEntities.emplace_back(enemy);
            }
          }
        }
      }
    }
  }

  if (!deleteEntities.empty()) {
    for (auto &ent : deleteEntities) {
      GetEntityManager().DeleteEntity(ent->GetId());
    }
  }
}
