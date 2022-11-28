#include "game/systems/DoorSystem.h"

#include <game/components/DoorComponent.h>
#include <game/components/ColliderComponent.h>

// TODO: Refactor

void DoorSystem::OnUpdate() {
    for (auto &playerEntity : *GetEntityManager().GetByTag("player")) {
        for (auto &eCol : playerEntity->Get<ColliderComponent>()->GetCollisions()) {
            if (eCol->Contains<DoorComponent>()) {
                ctx_->scene_ = "levelStats";
            }
        }
    }
}


DoorSystem::DoorSystem(EntityManager *const entity_manager, SystemManager *const system_manager,
                                         Context *ctx)
        : ISystem(entity_manager, system_manager), ctx_(ctx) {}
