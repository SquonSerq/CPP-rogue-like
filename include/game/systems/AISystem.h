#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class AISystem : public ISystem {
 public:
  void OnUpdate() override;

  AISystem(EntityManager *entityManager, SystemManager *systemManager);
};
