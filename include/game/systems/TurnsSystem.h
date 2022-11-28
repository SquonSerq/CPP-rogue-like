#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>
#include <lib/scenes/context.h>

class TurnsSystem : public ISystem {
  Context *ctx_;

 protected:
  void OnUpdate() override;

 public:
  TurnsSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};
