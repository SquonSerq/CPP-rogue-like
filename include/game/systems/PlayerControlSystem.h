#pragma once

#include <Controls.h>
#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class Entity;

class PlayerControlSystem : public ISystem {
  const Controls &controls_;

  bool OnUpdateEntity(Entity *entity) const;

 protected:
  void OnUpdate() override;

 public:
  PlayerControlSystem(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls);
};
