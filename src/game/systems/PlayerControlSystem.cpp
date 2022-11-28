#include "game/systems/PlayerControlSystem.h"

#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/TurnsComponent.h>

bool PlayerControlSystem::OnUpdateEntity(Entity *entity) const {
  auto mc = entity->Get<MovementComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();

  if (pcc->isMovable) {
    if (controls_.IsPressed(pcc->up_button_)) {
      mc->direction_.y = -1;
      return true;
    } else if (controls_.IsPressed(pcc->down_button_)) {
      mc->direction_.y = 1;
      return true;
    } else if (controls_.IsPressed(pcc->left_button_)) {
      mc->direction_.x = -1;
      return true;
    } else if (controls_.IsPressed(pcc->right_button)) {
      mc->direction_.x = 1;
      return true;
    } else {
      mc->direction_ = {0, 0};
    }
  }
  return false;
}

void PlayerControlSystem::OnUpdate() {
  TurnsComponent *etc;
  for (auto &e : GetEntityManager()) {
    if (e.Contains<TurnsComponent>()) {
      etc = e.Get<TurnsComponent>();
      break;
    }
  }

  for (auto &playerEntity : *GetEntityManager().GetByTag("player")) {
    bool res = OnUpdateEntity(playerEntity);

    if (res) {
      etc->isTurn = true;
    } else {
      etc->isTurn = false;
    }
  }
}

PlayerControlSystem::PlayerControlSystem(EntityManager *const entity_manager, SystemManager *const system_manager,
                                         const Controls &controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}
