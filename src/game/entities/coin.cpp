#include "game/entities/coin.h"

#include <game/components/CoinComponent.h>
#include <game/components/ColliderComponent.h>
#include <game/components/PickableComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/ColorComponent.h>

Entity* CreateCoinAt(EntityManager *entityManager, Vec2 pos, int coinAmount) {
  auto coin = entityManager->CreateEntity();

  coin->Add<TransformComponent>(pos);
  coin->Add<TextureComponent>('$');
  coin->Add<ColorComponent>(255, 230, 188, 21);
  coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
  coin->Add<PickableComponent>();
  coin->Add<CoinComponent>(coinAmount);
  return coin;
}
