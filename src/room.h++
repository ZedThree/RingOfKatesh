#ifndef ROOM_H
#define ROOM_H

#include "creature.h++"
#include "exits.h++"
#include "player.h++"
#include <iostream>
#include <vector>
#include <string>

class Room {
private:
  typedef std::vector<Creature> creature_list;

  std::string name;		// Name of the room
  std::string description;	// Brief description of the room

  // The enemies in the room
  creature_list enemies;

public:
  Exits doors;

  Room();
  Room(std::string n, std::string desc, creature_list e, Exits d) :
    name(n),
    description(desc),
    enemies(e),
    doors(d) {}

  // Iterators so the engine can access the list of creatures in the room
  typedef creature_list::iterator enemy_iterator;
  enemy_iterator firstEnemy() { return enemies.begin(); }
  enemy_iterator lastEnemy() { return enemies.end(); }

  // void exit(Room direction);

  void enter(Player& player);	// Things to do when entering a room

  void printDescription();	// Print a description of the room
  void printEnemies();		// Print out the list of enemies

  // Getters and setters
  void killEnemy( enemy_iterator enemy ) { enemies.erase(enemy); }

  int enemiesLeft() { return enemies.size(); }

};

#endif
