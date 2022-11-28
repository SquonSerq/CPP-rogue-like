#pragma once

#include <lib/ecs/entity.h>
#include <lib/math/vec2.h>

#include <iostream>
#include <vector>

#include "lib/ecs/component.h"

// One of the game rules is that character can go only one tile per turn.
// It means we don't have to use var speed, because it's constant.
// We can declare it here as const but in my opinion it's not necessary.

class MovementComponent : public IComponent {
  std::vector<Entity *> obstacleEntities{};

 public:
  Vec2 direction_;

  const std::vector<Entity *> &GetObstacles() const {
    return obstacleEntities;
  }

  bool AnyObstacles() const {
    return !obstacleEntities.empty();
  }

  void AddObstacle(Entity *entity) {
    obstacleEntities.emplace_back(entity);
  }

  void Clear() {
    obstacleEntities.clear();
  }

  void DeleteObstacle(size_t id) {
    int counter = 0;
    for (auto &e : obstacleEntities) {
      if (e->GetId() == id) {
        obstacleEntities.erase(obstacleEntities.begin() + counter);
      }
      counter++;
    }
  }

  explicit MovementComponent(Vec2 dir = ZeroVec2) : direction_(dir) {}
};
