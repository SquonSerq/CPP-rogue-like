#include "game/utils/SceneRenderer.h"

#include <BearLibTerminal.h>
#include <game/components/ColorComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

void SceneRenderer::Render(Entity *entity) {
  if (entity->Contains<TransformComponent>() && entity->Contains<TextureComponent>()) {
    auto transform = entity->Get<TransformComponent>();
    auto texture = entity->Get<TextureComponent>();

    if (entity->Contains<ColorComponent>()) {
        auto colors = entity->Get<ColorComponent>();
        terminal_color(color_from_argb(colors->alpha_, colors->red_, colors->green_, colors->blue_));
    }

    terminal_put(transform->pos_.x, transform->pos_.y, texture->symbol_);

    terminal_color(color_from_argb(255, 255, 255, 255));
  }
}
