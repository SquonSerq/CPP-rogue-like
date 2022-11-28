#include "game/editor/systems/EditorEntityCreator.h"

#include <game/components/PlayerControlComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

bool EditorEntityCreator::Check(const Entity &entity) {
  auto tc = entity.Get<TransformComponent>();
  bool canBeSet = true;
  for (auto &check : GetEntityManager()) {
    if (check.Contains<TransformComponent>() && !check.Contains<PlayerControlComponent>()) {
      if (check.Get<TransformComponent>()->pos_ == tc->pos_) {
        canBeSet = false;
      }
    }
  }
  return canBeSet;
}

void EditorEntityCreator::OnUpdate() {
  for (auto &ct : GetEntityManager()) {
    auto tc = ct.Get<TransformComponent>();
    if (controls_.IsPressed(TK_J)) {
      if (Check(ct)) {
        {
          auto wall = GetEntityManager().CreateEntity();

          wall->Add<TransformComponent>(Vec2{tc->pos_.x, tc->pos_.y});
          wall->Add<TextureComponent>('#');
        }
      }
    } else if (controls_.IsPressed(TK_K)) {
      if (Check(ct)) {
        {
          auto player = GetEntityManager().CreateEntity();

          player->Add<TransformComponent>(Vec2{tc->pos_.x, tc->pos_.y});
          player->Add<TextureComponent>('@');
        }
      }
    } else if (controls_.IsPressed(TK_H)) {
      for (auto &ent : GetEntityManager()) {
        if (!ent.Contains<PlayerControlComponent>() && ent.Contains<TransformComponent>()) {
          if (ent.Get<TransformComponent>()->pos_ == tc->pos_) {
            GetEntityManager().DeleteEntity(ent.GetId());
            break;
          }
        }
      }
      break;
    } else if (controls_.IsPressed(TK_L)) {
      if (Check(ct)) {
        {
          auto coin = GetEntityManager().CreateEntity();

          coin->Add<TransformComponent>(Vec2{tc->pos_.x, tc->pos_.y});
          coin->Add<TextureComponent>('$');
        }
      }
    } else if (controls_.IsPressed(TK_N)) {
      if (Check(ct)) {
        {
          auto door = GetEntityManager().CreateEntity();

          door->Add<TransformComponent>(Vec2{tc->pos_.x, tc->pos_.y});
          door->Add<TextureComponent>('>');
        }
      }
    } else if (controls_.IsPressed(TK_M)) {
      if (Check(ct)) {
        {
          auto enemy = GetEntityManager().CreateEntity();

          enemy->Add<TransformComponent>(Vec2{tc->pos_.x, tc->pos_.y});
          enemy->Add<TextureComponent>('E');
        }
      }
    } else if (controls_.IsPressed(TK_DELETE)) {
      for (auto &ent : GetEntityManager()) {
        if (!ent.Contains<PlayerControlComponent>()) {
          GetEntityManager().DeleteEntity(ent.GetId());
        }
      }
    }
  }
}

EditorEntityCreator::EditorEntityCreator(EntityManager *const entity_manager, SystemManager *const system_manager,
                                         const Controls &controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}
