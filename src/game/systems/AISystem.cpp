#include "game/systems/AISystem.h"

#include <game/components/AIComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/TurnsComponent.h>

void AISystem::OnUpdate() {
  for (auto &entity : *GetEntityManager().GetByTag("enemies")) {
    if (entity->Contains<AIComponent>()) {
      auto sysEnt = GetEntityManager().GetByTag("system")->at(0);
      auto ptc = GetEntityManager().GetByTag("player")->at(0)->Get<TransformComponent>();
      auto mc = entity->Get<MovementComponent>();
      auto tc = entity->Get<TransformComponent>();

      bool madeTurn = true;

      if (sysEnt->Contains<TurnsComponent>()) {
        madeTurn = sysEnt->Get<TurnsComponent>()->isTurn;
      }
      mc->direction_ = {0, 0};

      if (madeTurn) {
        if (ptc->pos_.x != tc->pos_.x) {
          if (mc->AnyObstacles()) {
            auto obst = mc->GetObstacles().at(0);
            if (!obst->Contains<PlayerControlComponent>()) {
              mc->direction_.y = -1;
              break;
            }
          }
          if (ptc->pos_.x > tc->pos_.x) {
            mc->direction_.x = 1;
          } else {
            mc->direction_.x = -1;
          }
        } else if (ptc->pos_.y != tc->pos_.y) {
          if (ptc->pos_.y > tc->pos_.y) {
            mc->direction_.y = 1;
          } else {
            mc->direction_.y = -1;
          }
        }
      }
    }
  }
}

AISystem::AISystem(EntityManager *entityManager, SystemManager *systemManager)
    : ISystem(entityManager, systemManager) {}
