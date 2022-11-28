#pragma once

#include <game/utils/IRender.h>

class EditorRenderer : public IRender {
 public:
  void Render(Entity *entity);
};
