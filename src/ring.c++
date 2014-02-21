#include "dice.h++"
#include "creature.h++"
#include "potion.h++"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {

  Potion* potion = new Potion;

  // Initialise the random number generator
  std::srand(std::time(0));

  Creature player("player", 10, Dice(6, 2), Dice(6, 2));
  Creature kobold("kobold", 4, Dice(4, 3), Dice(4, 2));

  std::cout << "Your start health: " << player.getHp() << "\n";
  std::cout << "Kobold start health: " << kobold.getHp() << "\n\n";

  std::string choice;
  bool moves;

  do {
    moves = true;
    do {
      std::cout << "\nWhat do you want to do?\n";
      std::cout << "Attack, potion or quit?\n> ";
      std::getline(std::cin, choice);

      if (choice == "quit") {

	std::cout << "You cowardly run away\n";
	return 0;

      } else if (choice == "attack") {

	std::cout << "You attack the kobold\n";
	player.attack(kobold);
	std::cout << "Kobold health: " << kobold.getHp() << std::endl;
	moves = false;

      } else if (choice == "potion") {

	if (potion) {
	  std::cout << "You use a potion (you have 1)\n";
	  potion->use(player);
	  delete potion;
	  potion = nullptr;
	  std::cout << "Your health: " << player.getHp() << std::endl;
	  moves = false;
	} else {
	  std::cout << "Sorry, you have no more potions!\n";
	}
      }
    } while (moves);

    if ( !kobold.isAlive() ) {
      break;
    }

    std::cout << "\nNow it's the kobold's turn!\n";

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
