#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "creature.h++"
#include "potion.h++"
#include <cstdlib>
#include <ctime>
#include <vector>

class Engine {
private:
  bool running;
  Creature player;
  Potion* potion = new Potion;

  // A list of enemy creatures
  std::vector<Creature> enemy_list;

public:
  Engine() : running(true),
	     player("player", 10, Dice(6, 2), Dice(6, 2)) {}

  void start();

  void play();

  void playerTurn();

  void enemyTurn();

  // void quit();

  bool isRunning() { return running; }

};

#endif
