#pragma once

#include <lib/ecs/engine.h>

#include <string>

class RoomSaver {
  const Engine *engine_;
  std::string path_;

 public:
  void Save();

  RoomSaver(const Engine *engine, std::string path);
};
