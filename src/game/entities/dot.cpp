#include "game/entities/dot.h"

#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

void CreateDotAt(EntityManager *entityManager, Vec2 pos) {
  auto dot = entityManager->CreateEntity();

  dot->Add<TransformComponent>(pos);
  dot->Add<TextureComponent>('.');
}
