#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class MovementSystem : public ISystem {
 public:
  MovementSystem(EntityManager *entity_manager, SystemManager *system_manager);

 protected:
  void OnUpdate() override;
};
