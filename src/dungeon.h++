#ifndef DUNGEON_H
#define DUNGEON_H

#include "enums.h++"
#include "room.h++"
#include "boost/multi_array.hpp"
#include <array>

class Dungeon {
private:
  // Size of the dungeon
  int DUNGEON_DIMS = 3;

  typedef boost::multi_array<Room, 2> dungeon_type;
  typedef dungeon_type::index index;
  typedef std::array<int,2> coords;

  // The array of rooms
  dungeon_type map;

public:
  Dungeon();

  // Check whether it's possible to move in direction from position
  bool movePossible(coords position, global_enums::Directions direction);

  // Return a pointer to the room at position
  Room* getRoom(coords position);

};

#endif
