#include "game/editor/systems/EditorController.h"

#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

EditorController::EditorController(EntityManager *const entity_manager, SystemManager *const system_manager,
                                   const Controls &controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}

void EditorController::OnUpdate() {
  for (auto &e : GetEntityManager()) {
    if (e.Contains<PlayerControlComponent>() && e.Contains<MovementComponent>()) {
      auto pcc = e.Get<PlayerControlComponent>();
      auto tc = e.Get<TransformComponent>();
      if (controls_.IsPressed(pcc->up_button_)) {
        tc->pos_.y -= 1;
      } else if (controls_.IsPressed(pcc->down_button_)) {
        tc->pos_.y += 1;
      } else if (controls_.IsPressed(pcc->left_button_)) {
        tc->pos_.x -= 1;
      } else if (controls_.IsPressed(pcc->right_button)) {
        tc->pos_.x += 1;
      }
    }
  }
}
