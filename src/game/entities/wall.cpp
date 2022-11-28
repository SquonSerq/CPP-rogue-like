#include "game/entities/wall.h"

#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/WallComponent.h>

Entity* CreateWallAt(EntityManager *entityManager, Vec2 pos) {
  auto wall = entityManager->CreateEntity();

  wall->Add<TransformComponent>(pos);
  wall->Add<TextureComponent>('#');
  wall->Add<WallComponent>();
  return wall;
}
