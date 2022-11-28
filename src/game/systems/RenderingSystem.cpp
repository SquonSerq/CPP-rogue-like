#include "game/systems/RenderingSystem.h"

#include <BearLibTerminal.h>
#include <game/utils/IRender.h>

#include <vector>

void RenderingSystem::OnUpdate() {
  for (auto &render : renderers_) {
    for (auto &e : GetEntityManager()) {
      render->Render(&e);
    }
  }
}

void RenderingSystem::OnPreUpdate() {
  terminal_clear();
}

void RenderingSystem::OnPostUpdate() {
  terminal_refresh();
}

RenderingSystem::RenderingSystem(EntityManager *const entity_manager, SystemManager *const system_manager,
                                 const std::vector<IRender *> &renders)
    : ISystem(entity_manager, system_manager), renderers_(renders) {}

void RenderingSystem::AddRender(IRender render) {
  renderers_.push_back(&render);
}
