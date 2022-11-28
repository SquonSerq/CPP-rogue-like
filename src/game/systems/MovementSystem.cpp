
#include <game/components/MovementComponent.h>
#include <game/components/PickableComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/TriggerComponent.h>
#include <game/components/TurnsComponent.h>
#include <game/systems/MovementSystem.h>

MovementSystem::MovementSystem(EntityManager *const entity_manager, SystemManager *const system_manager)
    : ISystem(entity_manager, system_manager) {}

void MovementSystem::OnUpdate() {
  //  True, because if we don't have system entity with TurnsComponent, we still can use MovementSystem
  bool madeTurn = true;
  //  No need to use tag system because system entity always first in EntityManager
  for (auto &entity : GetEntityManager()) {
    if (entity.Contains<TurnsComponent>()) {
      madeTurn = entity.Get<TurnsComponent>()->isTurn;
      break;
    }
  }

  if (madeTurn) {
    for (auto &entity : *GetEntityManager().GetByTag("MovementSystem")) {
      auto tc = entity->Get<TransformComponent>();
      auto mc = entity->Get<MovementComponent>();
      mc->Clear();

      // TODO: Separate collision prediction logic from movement system.
      if (mc->direction_.x != 0 || mc->direction_.y != 0) {
        for (auto &e : GetEntityManager()) {
          if (e.Contains<TransformComponent>() && !e.Contains<PickableComponent>() && !e.Contains<TriggerComponent>()) {
            if (e.Get<TransformComponent>()->pos_ == tc->pos_ + mc->direction_) {
              mc->direction_ = ZeroVec2;
              mc->AddObstacle(&e);
            }
          }
        }
      }

      tc->pos_ += mc->direction_;
    }
  }
}
