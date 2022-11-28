#include "game/entities/door.h"

#include <game/components/ColliderComponent.h>
#include <game/components/DoorComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/TriggerComponent.h>
#include <game/components/ColorComponent.h>

Entity* CreateDoorAt(EntityManager *entityManager, Vec2 pos) {
  auto door = entityManager->CreateEntity();

  door->Add<TransformComponent>(pos);
  door->Add<TextureComponent>('>');
  door->Add<ColorComponent>(255, 230, 21, 163);
  door->Add<ColliderComponent>(OnesVec2, ZeroVec2);
  door->Add<DoorComponent>("levelStats");
  door->Add<TriggerComponent>();
  return door;
}
