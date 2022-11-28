#pragma once

#include <game/utils/IReader.h>
#include <lib/ecs/entity_manager.h>

#include <string>
#include <vector>

class RoomReader : public IReader {
  EntityManager *entityManager_;
  std::string sourcePath_;

 public:
  void ReadFile() override;

  RoomReader(EntityManager *entityManager, const std::string &sourcePath);
};
