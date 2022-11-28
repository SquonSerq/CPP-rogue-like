#include "game/editor/utils/EditorRenderer.h"

#include <BearLibTerminal.h>
#include <game/components/ColorComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

void EditorRenderer::Render(Entity *entity) {
  for (int i = 0; i < 50; ++i) {
    terminal_put(140, i, '|');
  }

  for (int i = 0; i < 170; ++i) {
      terminal_put(i, 47, '-');
  }

  if (entity->Contains<TransformComponent>() && entity->Contains<TextureComponent>()) {
    if (entity->Contains<PlayerControlComponent>()) {
      terminal_layer(3);
    }
    if (entity->Contains<ColorComponent>()) {
      auto colors = entity->Get<ColorComponent>();
      terminal_color(color_from_argb(colors->alpha_, colors->red_, colors->green_, colors->blue_));
    }

    terminal_put(entity->Get<TransformComponent>()->pos_.x, entity->Get<TransformComponent>()->pos_.y,
                 entity->Get<TextureComponent>()->symbol_);

    terminal_layer(1);
    terminal_color(color_from_argb(255, 255, 255, 255));
  }

  terminal_print(0, 48, "(BACKSPACE) BACK TO TITLE | (DELETE) DELETE ALL");
  terminal_print(0, 49, "(H) DELETE | (J) WALL | (K) PLAYER | (L) COIN | (N) DOOR | (M) ENEMY | (O) OPEN | (P) SAVE");
}
