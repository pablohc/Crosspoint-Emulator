#pragma once

// Sim stub for device hal/HalStorage.h. On device this is the storage HAL;
// in the emulator we forward to SDCardManager so the same app code compiles.

#include "SDCardManager.h"
#include "SdFat.h"

class HalStorage {
 public:
  bool begin() { return SdMan.begin(); }
  bool ready() const { return SdMan.ready(); }
  FsFile open(const char* path, oflag_t oflag = O_RDONLY) { return SdMan.open(path, oflag); }
  bool exists(const char* path) { return SdMan.exists(path); }
  bool mkdir(const char* path, bool pFlag = true) { return SdMan.mkdir(path, pFlag); }
  bool remove(const char* path) { return SdMan.remove(path); }
  bool rmdir(const char* path) { return SdMan.rmdir(path); }

  static HalStorage& getInstance() {
    static HalStorage s;
    return s;
  }
};
