#include <game/components/TransformComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/BattleComponent.h>
#include <game/components/HealthComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/AIComponent.h>
#include "game/entities/enemy.h"

Entity* CreateEnemyAt(EntityManager *entityManager, Vec2 pos) {
    auto enemy = entityManager->CreateEntity();

    enemy->Add<TransformComponent>(pos);
    enemy->Add<TextureComponent>('E');
    enemy->Add<MovementComponent>();
    enemy->Add<HealthComponent>(5);
    enemy->Add<BattleComponent>(5);
    enemy->Add<AIComponent>();
    return enemy;
}
