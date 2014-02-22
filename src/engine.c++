#include "engine.h++"
#include "dice.h++"
#include "creature.h++"
#include "potion.h++"
#include <iostream>
#include <string>

void Engine::play() {

  // start in the first room of the map

  std::string choice;
  bool moves;

  // main loop
  do {
    moves = true;
    do {
      std::cout << "\nWhat do you want to do?\n";
      std::cout << "Attack, potion or quit?\n> ";
      std::getline(std::cin, choice);

      if (choice == "quit") {

	std::cout << "You cowardly run away\n";
	return;

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

  return;

}
