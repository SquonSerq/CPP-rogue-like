#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>
#include <lib/scenes/context.h>

class DoorSystem : public ISystem {
    Context *ctx_;
 public:
  void OnUpdate() override;

  DoorSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};
