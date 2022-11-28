#pragma once

#include <string>

class FilePathComponent : public IComponent {
 public:
  std::string path_;

  explicit FilePathComponent(std::string path) : path_(path){}
};
