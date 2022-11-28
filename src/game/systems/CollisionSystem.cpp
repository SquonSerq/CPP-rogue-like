#include "game/systems/CollisionSystem.h"

#include <game/components/ColliderComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/TransformComponent.h>
#include <lib/ecs/entity.h>

static bool Filter(const Entity &entity) {
  return entity.Contains<ColliderComponent>() && entity.Contains<TransformComponent>();
}

static void Collide(Entity *entity_1, Entity *entity_2) {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  auto cc2 = entity_2->Get<ColliderComponent>();

  auto tc1 = entity_1->Get<TransformComponent>();
  auto tc2 = entity_2->Get<TransformComponent>();

  if (tc1->pos_ == tc2->pos_) {
    cc2->Collide(entity_1);
  }
}

CollisionSystem::CollisionSystem(EntityManager *const entity_manager, SystemManager *const system_manager)
    : ISystem(entity_manager, system_manager) {}

void CollisionSystem::OnUpdate() {
  for (auto &colEnt : *GetEntityManager().GetByTag("Collider")) {
    if (colEnt->Contains<ColliderComponent>()) {
      colEnt->Get<ColliderComponent>()->Clear();
    }
  }

  for (auto &entity_1 : *GetEntityManager().GetByTag("Collider")) {
    if (Filter(*entity_1)) {
      for (auto &entity_2 : *GetEntityManager().GetByTag("Collider")) {
        if (Filter(*entity_2)) {
          Collide(entity_1, entity_2);
        }
      }
    }
  }
}
