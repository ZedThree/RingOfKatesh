#include "dice.h++"
#include "creature.h++"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

  // Initialise the random number generator
  std::srand(std::time(0));

  Creature player("player", 5, Dice(6, 2), Dice(6, 2));
  Creature kobold("kobold", 4, Dice(4, 3), Dice(4, 2));

  std::cout << "Your start health: " << player.getHp() << "\n";
  std::cout << "Kobold start health: " << kobold.getHp() << "\n\n";

  do {
    std::cout << "You attack the kobold\n";
    player.attack(kobold);
    std::cout << "Kobold health: " << kobold.getHp() << std::endl;

    if ( !kobold.isAlive() ) {
      break;
    }

    std::cout << "The kobold attacks you\n";
    kobold.attack(player);
    std::cout << "Your health: " << player.getHp() << std::endl;

  } while (player.isAlive() && kobold.isAlive() );

  if (player.isAlive()) {
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }

  return 0;
}
