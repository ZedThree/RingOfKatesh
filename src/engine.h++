#ifndef ENGINE_H
#define ENGINE_H

#include "creature.h++"
#include "creature_types.h++"
#include "dice.h++"
#include "potion.h++"
#include "room.h++"
#include <iostream>
#include <string>
#include <vector>

class Engine {
private:
  Creature player;
  Potion* potion = new Potion;
  Room* room;

  // A list of enemy creatures
  std::vector<Creature>* enemy_list;

public:
  Engine(Room* start_room) : player("player", 10, Dice(6, 2), Dice(6, 2)), room(start_room) {}

  void start();

  void play();

  // void quit();

};

#endif
