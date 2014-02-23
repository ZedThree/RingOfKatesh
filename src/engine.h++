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
  Creature player;
  Potion* potion = new Potion;

  // A list of enemy creatures
  std::vector<Creature> enemy_list;

public:
  Engine() : player("player", 10, Dice(6, 2), Dice(6, 2)) {}

  void start();

  void play();

  // void quit();

};

#endif
