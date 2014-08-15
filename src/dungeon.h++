#ifndef DUNGEON_H
#define DUNGEON_H

#include "enums.h++"
#include "exits.h++"
#include "globals.h++"
#include "room.h++"
#include <boost/multi_array.hpp>
#include <array>
#include <map>
#include <string>

enum class Directions {
  NORTH = 0,
  EAST,
  SOUTH,
  WEST,
};

class Dungeon {
private:
  // Array of rooms
  typedef boost::multi_array<Room, 2> dungeon_type;
  typedef dungeon_type::index index;

  // The array of rooms
  dungeon_type map;

  // Coordinates of the starting room
  coords start_room;

  // Characters for printing map
  std::map<Exits, std::string> room_chars;

  // Pick a direction - used in generating a dungeon
  int pickDir() { return (std::rand() % 5) + 1; }
public:
  Dungeon();

  // Check whether it's possible to move in direction from position
  bool movePossible(coords position, global_enums::Directions direction);

  // Return a pointer to the room at position
  Room* getRoom(coords position);

  // Print the dungeon to screen
  void printDungeon();
  // Version with the player position blinking
  void printDungeon(coords player_pos);

  // Get the x-coordinate of the starting room
  // -- we always start at y=0
  int getStartRoom() { return start_room[0]; }
};

#endif
