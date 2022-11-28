#include "game/editor/utils/EditorRoomReader.h"

#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <lib/math/vec2.h>

#include <fstream>
#include <vector>
#include <string>

EditorRoomReader::EditorRoomReader(EntityManager *entityManager, const std::string &sourcePath)
    : entityManager_(entityManager), sourcePath_(sourcePath) {}

void EditorRoomReader::ReadFile() {
  std::ifstream file;
  file.open(sourcePath_);

  if (file.is_open()) {
    std::vector<std::string> strings;
    std::string tempstr = "";
    while (file >> tempstr) {
      strings.emplace_back(tempstr);
    }

    // TODO: Make map <char, func> instead of hardcode

    int i = 0;
    int j = 0;

    for (std::string str : strings) {
      for (char ch : str) {
        if (ch == '#') {
          {
            auto wall = entityManager_->CreateEntity();

            wall->Add<TransformComponent>(Vec2{i, j});
            wall->Add<TextureComponent>('#');
          }
        } else if (ch == '@') {
          {
            auto player = entityManager_->CreateEntity();

            player->Add<TransformComponent>(Vec2{i, j});
            player->Add<TextureComponent>('@');
          }
        } else if (ch == '$') {
          {
            auto coin = entityManager_->CreateEntity();

            coin->Add<TransformComponent>(Vec2{i, j});
            coin->Add<TextureComponent>('$');
          }
        } else if (ch == '>') {
          {
            auto door = entityManager_->CreateEntity();

            door->Add<TransformComponent>(Vec2{i, j});
            door->Add<TextureComponent>('>');
          }
        }
        i++;
      }
      i = 0;
      j++;
    }
  }
}
