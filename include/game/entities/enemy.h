#pragma once

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <lib/math/vec2.h>

Entity * CreateEnemyAt(EntityManager *entityManager, Vec2 pos);
