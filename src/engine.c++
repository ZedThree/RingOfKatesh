#include "engine.h++"
#include "room.h++"
#include <array>

void Engine::start() {

  // start in the first room of the map

  std::cout << "\nYour start health: " << player.getHp() << "\n\n";

  // Get player coordinates
  std::array<int,2> coords;
  coords = player.getPosition();

  room = dungeon.getRoom(coords);

  // Enter the first room
  room->enter();
}

void Engine::play() {

  // Some initial set-up
  start();

  // Main loop
  do {

    playerTurn();

    if (!isRunning()) {
      return;
    }

    enemyTurn();

  } while (isRunning() && player.isAlive() && room->enemiesLeft()>0 );

  if (player.isAlive()) {
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }

  return;

}

void Engine::playerTurn() {

  // Choice of action
  std::string choice;
  // Does the player have any moves?
  bool moves = true;
  // The iterator for the list of enemies
  Room::enemy_iterator current_enemy;

  do {
    std::cout << "\nWhat do you want to do? [Type (h)elp for options]\n> ";
    std::getline(std::cin, choice);

    if (choice == "quit" || choice == "q") {
      running = false;
      std::cout << "You cowardly run away\n";
      return;

    } else if (choice == "attack" || choice == "a") {

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

    } else if (
	       choice == "north" || choice == "n" ||
	       choice == "east"  || choice == "e" ||
	       choice == "south" || choice == "s" ||
	       choice == "west"  || choice == "w"
	       ) {
      std::cout << "Not yet implemented, but you can try it...\n";

      std::cout << "Before: ";
      std::cout << player.getPosition()[0] << player.getPosition()[1] << std::endl;
      movePlayer(choice);
      std::cout << "After: ";
      std::cout << player.getPosition()[0] << player.getPosition()[1] << std::endl;
      room = dungeon.getRoom(player.getPosition());
      room->enter();

    } else if (choice == "help" || choice == "h") {

      std::cout << "Things you can do: (n)orth, (e)ast, (s)outh, (w)est, (a)ttack, (q)uit or potion\n";

    } else {

      std::cout << "I'm not sure how to do that. Maybe try again? Type (h)elp for some help.\n";

    }
  } while (moves);

}

void Engine::enemyTurn() {
  // The iterator for the list of enemies
  Room::enemy_iterator current_enemy;

  // Loop over the enemies and attack the player
  current_enemy = room->firstEnemy();
  while (current_enemy != room->lastEnemy() ) {
    // If this enemy is dead, remove it from the list and skip its turn
    if ( !current_enemy->isAlive() ) {
      room->killEnemy(current_enemy);
      continue;
    }

    if (!player.isAlive()) {
      break;
    }

    std::string enemy_name = current_enemy->getName();
    std::cout << "\nNow it's the " << enemy_name <<"'s turn!\n";
    std::cout << "The " << enemy_name << " attacks you\n";
    current_enemy->attack(player);
    std::cout << "Your health: " << player.getHp() << std::endl;

    // Next enemy
    current_enemy++;
  }
}

// Move player to a new position
void Engine::movePlayer(std::string direction) {

  std::array<int,2> player_pos = player.getPosition();

  if (direction == "north" || direction == "n") {

    player_pos[1]++;
    player.move(player_pos);

  } else if (direction == "east"  || direction == "e") {

    player_pos[0]++;
    player.move(player_pos);

  } else if (direction == "south" || direction == "s") {

    player_pos[1]--;
    player.move(player_pos);

  } else if (direction == "west"  || direction == "w") {

    player_pos[0]--;
    player.move(player_pos);

  }
}
