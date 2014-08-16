#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h++"
#include "exits.h++"
#include "globals.h++"
#include "item.h++"
#include <array>
#include <boost/multi_array.hpp>
#include <map>
#include <string>
#include <vector>

class Player : public Creature {
private:
  // Array of room exits for map
  typedef boost::multi_array<Exits, 2> MapType;

  // Map of explored rooms
  MapType map;

  // Coordinates in the map
  Coords position;

  // Characters for printing map
  std::map<Exits, std::string> room_chars;

public:
  Player(int x) : Creature("player", 10, Dice(6, 2), Dice(6, 2)),
		  position({{x, 0}}) {
    // Create the player's map
    map.resize(boost::extents[DUNGEON_DIMS][DUNGEON_DIMS]);
    // Fill with unknown rooms
    std::fill(map.data(),
	      map.data()+map.num_elements(),
	      Exits(0,0,0,0));
}

  Coords getPosition() { return position; }

  void move(Coords new_position ) { position = new_position; }

  // Print the player's map
  void printMap();

  // Update the player's map with the current room
  void updateMap(Exits doors);

  // List inventory contents
  void printInventory();
  // Add item to inventory
  void takeItem(Item item);
  // Remove item from inventory
  // Probably want to give it *to* something
  void giveItem(Item item);

};


#endif
