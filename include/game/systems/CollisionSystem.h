#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class CollisionSystem : public ISystem {
 public:
  CollisionSystem(EntityManager *entity_manager, SystemManager *system_manager);

 protected:
  void OnUpdate() override;
};
