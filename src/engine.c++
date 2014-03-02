#include "engine.h++"
#include "dice.h++"
#include "creature.h++"
#include "creature_types.h++"
#include "potion.h++"
#include <iostream>
#include <string>
#include <vector>

void Engine::start() {
  // Initialise the random number generator
  std::srand(std::time(0));

  // start in the first room of the map

  // Make some enemies - this will be moved out to the starting room
  Kobold kobold;
  Rat rat;
  enemy_list.push_back(kobold);
  enemy_list.push_back(rat);

  std::cout << "\nYour start health: " << player.getHp() << "\n\n";

  // This section will be moved to room description
  std::cout << "There are " << enemy_list.size() << " enemies:\n";
  // The iterator for the list of enemies
  std::vector<Creature>::iterator current_enemy;
  // Iterate over list of enemies and announce their starting health
  current_enemy = enemy_list.begin();
  std::string enemy_announcement;
  while (current_enemy != enemy_list.end()) {
    enemy_announcement = current_enemy->getName() + " start health: ";
    std::cout << enemy_announcement << current_enemy->getHp() << "\n";
    current_enemy++;
  }
}

void Engine::play() {

  // Choice of action
  std::string choice;
  // Does the player have any moves?
  bool moves;
  // The iterator for the list of enemies
  std::vector<Creature>::iterator current_enemy;
  // Are there any enemies still alive?
  bool any_enemies_alive = false;

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

	// For now, can only attack the first enemy in the list
	current_enemy = enemy_list.begin();
	std::string enemy_name = current_enemy->getName();
	std::cout << "You attack the " << enemy_name << "\n";
	player.attack(*current_enemy);
	std::cout << enemy_name << " health: " << current_enemy->getHp() << std::endl;
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

    // We check in the enemy loop if any are alive
    any_enemies_alive = false;

    // Loop over the enemies and attack the player
    current_enemy = enemy_list.begin();
    while (current_enemy != enemy_list.end() ) {
      // If this enemy is dead, remove it from the list and skip its turn
      if ( !current_enemy->isAlive() ) {
	enemy_list.erase(current_enemy);
	continue;
      }
      // If it's not dead, there's at least one enemy alive
      any_enemies_alive = true;

      std::string enemy_name = current_enemy->getName();
      std::cout << "\nNow it's the " << enemy_name <<"'s turn!\n";
      std::cout << "The " << enemy_name << " attacks you\n";
      current_enemy->attack(player);
      std::cout << "Your health: " << player.getHp() << std::endl;

      // Next enemy
      current_enemy++;
    }

  } while (player.isAlive() && any_enemies_alive );

  if (player.isAlive()) {
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }

  return;

}
