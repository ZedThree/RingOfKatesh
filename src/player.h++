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

class Player : public Creature {
private:
  // Array of room exits for map
  typedef boost::multi_array<Exits, 2> map_type;
  typedef map_type::index index;

  // Map of explored rooms
  map_type map;

  // Coordinates in the map
  coords position;

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

  coords getPosition() { return position; }

  void move(coords new_position ) { position = new_position; }

  // Print the player's map
  void printMap();

  // Update the player's map with the current room
  void updateMap(Exits doors);

};


#endif
