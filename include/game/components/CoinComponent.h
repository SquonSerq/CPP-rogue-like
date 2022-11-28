#pragma once

class CoinComponent : public IComponent {
 public:
  int amount_;

  explicit CoinComponent(int amount) : amount_(amount) {}
};
