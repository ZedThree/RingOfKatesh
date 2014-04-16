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

// Check whether it's possible to move in direction from position
bool Dungeon::movePossible(coords position,
			   global_enums::Directions direction) {

  int x = position[0];
  int y = position[1];

  bool possible[4] = {0};

  // Simple check on edges
  // Northern edge
  possible[0] = ( y < DUNGEON_DIMS - 1 );
  // Eastern edge
  possible[1] = ( x < DUNGEON_DIMS - 1 );
  // Southern edge
  possible[2] = ( y > 0 );
  // Western edge
  possible[3] = ( x > 0 );

  // Will need more complicated check when I implement internal walls

  switch(direction) {
  case global_enums::NORTH :
    return possible[0];
  case global_enums::EAST :
    return possible[1];
  case global_enums::SOUTH :
    return possible[2];
  case global_enums::WEST :
    return possible[3];
  }
  return false;
}

// Return a pointer to the room at position
Room* Dungeon::getRoom(coords position) {
  return &map[position[0]][position[1]];
}
