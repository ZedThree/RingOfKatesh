#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "creature.h++"
#include "potion.h++"
#include <cstdlib>
#include <ctime>

class Engine {
private:
  Creature player;
  Creature kobold;
  Potion* potion = new Potion;

public:
  Engine() : player("player", 10, Dice(6, 2), Dice(6, 2)), kobold("kobold", 4, Dice(4, 3), Dice(4, 2)) {
    // Initialise the random number generator
    std::srand(std::time(0));

    std::cout << "Your start health: " << player.getHp() << "\n";
    std::cout << "Kobold start health: " << kobold.getHp() << "\n\n";

  }

  // void start();

  void play();

  // void quit();

};

#endif
