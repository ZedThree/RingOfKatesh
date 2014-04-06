#include "engine.h++"
#include "room.h++"

void Engine::start() {

  // start in the first room of the map

  std::cout << "\nYour start health: " << player.getHp() << "\n\n";

  // Enter the first room
  room->enter();
}

void Engine::play() {

  // Choice of action
  std::string choice;
  // Does the player have any moves?
  bool moves;
  // The iterator for the list of enemies
  Room::enemy_iterator current_enemy;
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
	current_enemy = room->firstEnemy();
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
    current_enemy = room->firstEnemy();
    while (current_enemy != room->lastEnemy()) {
      // If this enemy is dead, remove it from the list and skip its turn
      if ( !current_enemy->isAlive() ) {
	room->killEnemy(current_enemy);
	continue;
      }
      // If it's not dead, there's at least one enemy alive
      any_enemies_alive = true;

      std::string enemy_name = current_enemy->getName();
      std::cout << "\nNow it's the " << enemy_name <<"'s turn!\n";
      std::cout << "The " << enemy_name << " attacks you\n";
      current_enemy->attack(player);
      std::cout << "Your health: " << player.getHp() << std::endl;

      if ( !player.isAlive() ) {
	break;
      }

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
