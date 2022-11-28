#pragma once

#include <lib/ecs/component.h>
#include <lib/ecs/entity.h>
#include <lib/math/vec2.h>
#include <vector>

/**
 * Данный компонент - идеальный пример компонента с состоянием
 * Во множестве собирается информация о том, с кем произошло столкновение,
 * которое затем анализируется системой коллизий
 */

class ColliderComponent : public IComponent {
    std::vector<Entity *> collisions_{};

 public:
    Vec2 size_;
    Vec2 offset_;

    explicit ColliderComponent(const Vec2 &size, const Vec2 &offset = ZeroVec2) : size_(size), offset_(offset) {}

    const std::vector<Entity *> &GetCollisions() const {
        return collisions_;
    }

    bool AnyCollisions() const {
        return !collisions_.empty();
    }

    void Collide(Entity *entity) {
        collisions_.emplace_back(entity);
    }

    void Clear() {
        collisions_.clear();
    }

    void DeleteEntity(size_t id) {
        int counter = 0;
        for (auto &e : collisions_) {
            if (e->GetId() == id) {
                collisions_.erase(collisions_.begin()+counter);
            }
            counter++;
        }
    }
};
