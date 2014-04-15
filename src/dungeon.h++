#ifndef DUNGEON_H
#define DUNGEON_H

#include "room.h++"
#include "boost/multi_array.hpp"
#include <array>

class Dungeon {
private:
  int DUNGEON_DIMS = 3;

  typedef boost::multi_array<Room, 2> dungeon_type;
  typedef dungeon_type::index index;

  dungeon_type map;

public:
  Dungeon();

  bool movePossible();

  Room* getRoom(std::array<int,2> coords);

};

#endif
