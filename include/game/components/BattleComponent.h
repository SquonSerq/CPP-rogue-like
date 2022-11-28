#pragma once

class BattleComponent : public IComponent {
 public:
  int damage_;

  explicit BattleComponent(int damage) : damage_(damage) {}
};
