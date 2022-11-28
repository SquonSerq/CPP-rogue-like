#include "game/editor/utils/RoomSaver.h"

#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>

#include <fstream>
#include <string>
#include <vector>

RoomSaver::RoomSaver(const Engine *engine, std::string path) : engine_(engine), path_(path) {}

void RoomSaver::Save() {
  std::vector<std::string> lines;

  for (int i = 0; i < 49; ++i) {
    lines.emplace_back(
        ".............................................................................................................."
        "...............................");
  }

  for (auto &ent : *engine_->GetEntityManager()) {
    if (ent.Contains<TransformComponent>() && ent.Contains<TextureComponent>()) {
      auto tc = ent.Get<TransformComponent>();
      auto texc = ent.Get<TextureComponent>();
      if (tc->pos_.x < 139 && tc->pos_.x >= 0 && tc->pos_.y < 47 && tc->pos_.y >= 0) {
        lines[tc->pos_.y][tc->pos_.x] = texc->symbol_;
      }
    }
  }

  std::ofstream out_file;
  out_file.open(path_);

  for (auto &str : lines) {
    out_file << str << std::endl;
  }

  out_file.close();
}
