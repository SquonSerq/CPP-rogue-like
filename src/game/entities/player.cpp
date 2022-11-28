#include "game/entities/player.h"

#include <BearLibTerminal.h>
#include <game/components/ColliderComponent.h>
#include <game/components/InventoryComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/HealthComponent.h>
#include <game/components/ColorComponent.h>
#include <game/components/BattleComponent.h>

Entity* CreatePlayerAt(EntityManager *entityManager, Vec2 pos) {
  auto player = entityManager->CreateEntity();

  player->Add<TransformComponent>(pos);
  player->Add<MovementComponent>();
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(255, 21, 230, 198);
  player->Add<PlayerControlComponent>(TK_W, TK_S, TK_A, TK_D);
  player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
  player->Add<InventoryComponent>(0);
  player->Add<HealthComponent>(100);
  player->Add<BattleComponent>(100);
  return player;
}
