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
  bool running;
  Creature player;
  Potion* potion = new Potion;
  Room* room;

public:
  Engine(Room* start_room) : running(true),
			     player("player", 10, Dice(6, 2), Dice(6, 2)),
			     room(start_room) {}

  void start();

  void play();

  void playerTurn();

  void enemyTurn();

  // void quit();

  bool isRunning() { return running; }

};

#endif
