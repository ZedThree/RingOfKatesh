#include "dungeon.h++"

Dungeon::Dungeon() {
  map.resize(boost::extents[DUNGEON_DIMS][DUNGEON_DIMS]);

  // Initialise the dungeon with random rooms
  for (int x = 0; x < DUNGEON_DIMS; ++x) {
    for (int y = 0; y < DUNGEON_DIMS; ++y) {
      map[x][y] = Room();
    }
  }
}

Room* Dungeon::getRoom(std::array<int,2> coords) {
  return &map[coords[0]][coords[1]];
}
