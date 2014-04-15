#ifndef ENGINE_H
#define ENGINE_H

#include "creature.h++"
#include "creature_types.h++"
#include "dice.h++"
#include "dungeon.h++"
#include "player.h++"
#include "potion.h++"
#include "room.h++"
#include <iostream>
#include <string>
#include <vector>

class Engine {
private:
  bool running;
  Player player;
  Potion* potion = new Potion;
  Room* room;
  Dungeon dungeon;

public:
  Engine() : running(true),
	     player(),
	     dungeon() {}
	     // room(start_room) {}

  void start();

  void play();

  void playerTurn();

  void enemyTurn();

  void movePlayer(std::string direction);

  // void quit();

  bool isRunning() { return running; }

};

#endif
