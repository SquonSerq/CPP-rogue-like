#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>
#include <lib/scenes/context.h>

class BattleSystem : public ISystem {
    Context *ctx_;

 public:
  void OnUpdate() override;

  BattleSystem(EntityManager *entityManager, SystemManager *systemManager, Context *ctx);
};
