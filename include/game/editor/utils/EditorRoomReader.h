#pragma once

#include <game/utils/IReader.h>
#include <lib/ecs/entity_manager.h>

#include <string>

class EditorRoomReader : IReader {
  EntityManager *entityManager_;
  std::string sourcePath_;

 public:
  void ReadFile() override;

  EditorRoomReader(EntityManager *entityManager, const std::string &sourcePath);
};
