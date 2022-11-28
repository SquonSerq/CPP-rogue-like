#pragma once

#include <lib/ecs/entity_manager.h>
#include <lib/math/vec2.h>

Entity * CreateCoinAt(EntityManager *entityManager, Vec2 pos, int coinAmount);
