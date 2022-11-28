#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class InventorySystem : public ISystem {
 public:
  void OnUpdate() override;

  InventorySystem(EntityManager *entityManager, SystemManager *systemManager);
};
