#include "game/utils/LevelStatsRenderer.h"

#include <BearLibTerminal.h>
#include <game/components/InventoryComponent.h>
#include <game/components/TurnsComponent.h>

#include <string>

void LevelStatsRenderer::Render(Entity *entity) {
  if (entity->Contains<TurnsComponent>()) {
    auto tc = entity->Get<TurnsComponent>();

    terminal_printf(72, 25, "Turns: %i", tc->currentTurns_);
  }

  if (entity->Contains<InventoryComponent>()) {
    auto cc = entity->Get<InventoryComponent>();

    terminal_printf(72, 26, "Coins: %i", cc->coins_);
  }

  terminal_print(68, 22, "Congratulations!");
  terminal_print(66, 28, "Press SPACE to continue!");
}
