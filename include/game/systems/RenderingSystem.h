#pragma once

#include <game/utils/IRender.h>
#include <lib/ecs/entity_manager.h>
#include <lib/ecs/system_manager.h>

#include <vector>

class RenderingSystem : public ISystem {
  std::vector<IRender *> renderers_;

 protected:
  void OnPreUpdate() override;

  void OnUpdate() override;

  void OnPostUpdate() override;

 public:
  RenderingSystem(EntityManager *entity_manager, SystemManager *system_manager,
                  const std::vector<IRender *> &renderers);
  void AddRender(IRender render);
};
