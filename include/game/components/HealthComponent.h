#pragma once

class HealthComponent : public IComponent {
 public:
  int health_;

  explicit HealthComponent(int health) : health_(health) {}
};
