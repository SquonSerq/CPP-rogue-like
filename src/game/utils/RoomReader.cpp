#include "game/utils/RoomReader.h"

#include <game/entities/coin.h>
#include <game/entities/door.h>
#include <game/entities/enemy.h>
#include <game/entities/player.h>
#include <game/entities/wall.h>

#include <fstream>
#include <string>
#include <vector>

RoomReader::RoomReader(EntityManager *entityManager, const std::string &sourcePath)
    : entityManager_(entityManager), sourcePath_(sourcePath) {}

void RoomReader::ReadFile() {
  std::ifstream file;
  file.open(sourcePath_);

  if (file.is_open()) {
    std::vector<std::string> strings;
    std::string tempstr = "";
    while (file >> tempstr) {
      strings.emplace_back(tempstr);
    }

    // TODO: Make map <char, func> instead of hardcode

    int i = 1;
    int j = 1;

    for (std::string str : strings) {
      for (char ch : str) {
        if (ch == '#') {
          auto ent = CreateWallAt(entityManager_, Vec2{i, j});
          entityManager_->AddToTag("walls", ent);
        } else if (ch == '@') {
          auto ent = CreatePlayerAt(entityManager_, Vec2{i, j});
          entityManager_->AddToTag("player", ent);
          entityManager_->AddToTag("MovementSystem", ent);
          entityManager_->AddToTag("Collider", ent);
        } else if (ch == '$') {
          auto ent = CreateCoinAt(entityManager_, Vec2{i, j}, 1);
          entityManager_->AddToTag("coins", ent);
          entityManager_->AddToTag("Collider", ent);
        } else if (ch == '>') {
          auto ent = CreateDoorAt(entityManager_, Vec2{i, j});
          entityManager_->AddToTag("doors", ent);
          entityManager_->AddToTag("Collider", ent);
        } else if (ch == 'E') {
          auto ent = CreateEnemyAt(entityManager_, Vec2{i, j});
          entityManager_->AddToTag("enemies", ent);
          entityManager_->AddToTag("MovementSystem", ent);
        }
        i++;
      }
      i = 1;
      j++;
    }
  }
}
