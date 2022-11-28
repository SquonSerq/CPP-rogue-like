#include "game/utils/HUDRenderer.h"

#include <BearLibTerminal.h>
#include <game/components/HealthComponent.h>
#include <game/components/InventoryComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TurnsComponent.h>

#include <string>

void HUDRenderer::Render(Entity *entity) {
  for (int i = 0; i < 51; ++i) {
    terminal_put(140, i, '|');
  }

  if (entity->Contains<TurnsComponent>()) {
    auto tc = entity->Get<TurnsComponent>();

    terminal_printf(142, 2, "Turns: %i", tc->currentTurns_);
    terminal_printf(142, 5, "Turns left: %i", tc->turnsLimit_ - tc->currentTurns_);
  }

  if (entity->Contains<InventoryComponent>() && entity->Contains<PlayerControlComponent>()) {
    auto cc = entity->Get<InventoryComponent>();
    auto hp = entity->Get<HealthComponent>();

    terminal_printf(142, 3, "Coins: %i", cc->coins_);
    terminal_printf(142, 6, "Health: %i", hp->health_);
  }
}

HUDRenderer::HUDRenderer() = default;
