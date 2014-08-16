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
  typedef std::vector<Creature> CreatureList;

  std::string name;		// Name of the room
  std::string description;	// Brief description of the room

  // The enemies in the room
  CreatureList enemies;

public:
  Exits doors;

  Room();
  Room(std::string n, std::string desc, CreatureList e, Exits d) :
    name(n),
    description(desc),
    enemies(e),
    doors(d) {}

  // Iterators so the engine can access the list of creatures in the room
  typedef CreatureList::iterator EnemyIterator;
  EnemyIterator firstEnemy() { return enemies.begin(); }
  EnemyIterator lastEnemy() { return enemies.end(); }

  // void exit(Room direction);

  void enter(Player& player);	// Things to do when entering a room

  void printDescription();	// Print a description of the room
  void printEnemies();		// Print out the list of enemies

  // Getters and setters
  void killEnemy(EnemyIterator enemy) { enemies.erase(enemy); }

  int enemiesLeft() { return enemies.size(); }

};

#endif
