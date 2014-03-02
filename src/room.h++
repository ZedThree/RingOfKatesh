#ifndef ROOM_H
#define ROOM_H

#include "creature.h++"
#include <iostream>
#include <vector>
#include <string>

class Room {
private:
  typedef std::vector<Creature> creatureList;
  // Room* north;
  // Room* east;
  // Room* south;
  // Room* west;

  std::string name;		// Name of the room
  std::string description;	// Brief description of the room

public:
  // The enemies in the room. Needs to be public so the engine can modify it
  creatureList enemies;

  Room() {}
  Room(std::string n, std::string desc, creatureList e) :
    name(n), description(desc), enemies(e) {}

  // void exit(Room direction);

  void enter();			// Things to do when entering a room

  void printEnemies();		// Print out the list of enemies

};

#endif
