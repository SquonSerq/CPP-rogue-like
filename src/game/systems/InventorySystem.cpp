#include "game/systems/InventorySystem.h"

#include <game/components/CoinComponent.h>
#include <game/components/ColliderComponent.h>
#include <game/components/InventoryComponent.h>
#include <game/components/PickableComponent.h>

InventorySystem::InventorySystem(EntityManager *entityManager, SystemManager *systemManager)
    : ISystem(entityManager, systemManager) {}

void InventorySystem::OnUpdate() {
  for (auto &playerEntity : *GetEntityManager().GetByTag("player")) {
    auto cc = playerEntity->Get<ColliderComponent>();

    for (auto &entityCollision : cc->GetCollisions()) {
      if (entityCollision->Contains<PickableComponent>() && entityCollision->Contains<CoinComponent>()) {
        playerEntity->Get<InventoryComponent>()->coins_ += entityCollision->Get<CoinComponent>()->amount_;
        cc->DeleteEntity(entityCollision->GetId());
        GetEntityManager().DeleteEntity(entityCollision->GetId());
      }
    }
  }
}
