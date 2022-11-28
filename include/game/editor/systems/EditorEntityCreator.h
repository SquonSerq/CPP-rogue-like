#pragma once

#include <Controls.h>
#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

class EditorEntityCreator : public ISystem {
  const Controls &controls_;

 protected:
  void OnUpdate() override;

 public:
  EditorEntityCreator(EntityManager *entityManager, SystemManager *systemManager, const Controls &controls);

  bool Check(const Entity &entity);
};
