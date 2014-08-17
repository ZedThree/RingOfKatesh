#include "engine.h++"

void Engine::start() {

  Potion* potion = new Potion(5);
  Poison* poison = new Poison(2);

  player.inventory.addItem(potion);
  player.inventory.addItem(poison);

  // start in the first room of the map

  std::cout << "\nYour start health: " << player.getHp() << "\n\n";

  room = dungeon.getRoom(player.getPosition());

  // Enter the first room
  room->enter(player);
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

  } while (isRunning() && player.isAlive());

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
  Room::EnemyIterator current_enemy;

  do {
    std::cout << "\nWhat do you want to do? [Type (h)elp for options]\n> ";
    std::getline(std::cin, choice);

    if (choice == "quit" || choice == "q") {
      running = false;
      std::cout << "You cowardly run away\n";
      return;

    } else if (choice == "attack" || choice == "a") {

      // For now, can only attack the first enemy in the list
      if (room->enemiesLeft()) {
	current_enemy = room->firstEnemy();
	std::string enemy_name = current_enemy->getName();
	std::cout << "You attack the " << enemy_name << "\n";
	player.attack(*current_enemy);
	std::cout << enemy_name << " health: " << current_enemy->getHp() << std::endl;
	moves = false;
      } else {
	std::cout << "You swing at the air wildly. Good work.\n";
      }

    } else if (choice == "potion") {

      Item* potion = player.inventory.findItem("Potion");

      if (potion) {
      	std::cout << "You use a potion (you have "
      		  << potion->getNumber()-1 << " left)\n";
      	potion->use(player);
      	std::cout << "Your health: " << player.getHp() << std::endl;
      	moves = false;
      } else {
      	std::cout << "Sorry, you have no more potions!\n";
      }

    } else if (choice == "poison") {

      Item* poison = player.inventory.findItem("Poison");

      if (poison) {
      	std::cout << "You use a poison (you have "
      		  << poison->getNumber()-1 << " left)\n";
      	poison->use(player);
      	std::cout << "Your health: " << player.getHp() << std::endl;
      	moves = false;
      } else {
      	std::cout << "Sorry, you have no more poisons!\n";
      }

    } else if (choice == "north" || choice == "n" ||
	       choice == "east"  || choice == "e" ||
	       choice == "south" || choice == "s" ||
	       choice == "west"  || choice == "w") {
      // Well, this is awful. There must be a nicer way to turn
      // a string into an enum.
      // Maybe shift all this into a parser on choice?
      global_enums::Directions direction;
      if      (choice == "north" || choice == "n") direction = global_enums::NORTH;
      else if (choice == "east"  || choice == "e") direction = global_enums::EAST;
      else if (choice == "south" || choice == "s") direction = global_enums::SOUTH;
      else if (choice == "west"  || choice == "w") direction = global_enums::WEST;

      if (dungeon.movePossible(player.getPosition(), direction)) {
	movePlayer(direction);

	std::cout << "You are now at: ("
		  << player.getPosition()[0] << ","
		  << player.getPosition()[1] << ")\n";

	room = dungeon.getRoom(player.getPosition());
	room->enter(player);

	// Need some logic to skip enemy's turn if we've just moved
	// to a room
	// moves = false;
      } else {
	std::cout << "Sorry, that way is not possible\n" ;
      }

    } else if (choice == "look" || choice == "l") {

      room->printDescription();
      room->printEnemies();

    } else if (choice == "map" || choice == "m") {

      player.printMap();

    } else if (choice == "inventory" || choice == "i") {

      player.printInventory();

    } else if (choice == "help" || choice == "h") {

      std::cout << "Things you can do: (n)orth, (e)ast, (s)outh, (w)est, (a)ttack, (l)ook, (m)ap, (q)uit or potion\n";

    } else {

      std::cout << "I'm not sure how to do that. Maybe try again? Type (h)elp for some help.\n";

    }
  } while (moves);

  // Remove used items
  player.inventory.cleanupInventory();

}

void Engine::enemyTurn() {
  // The iterator for the list of enemies
  Room::EnemyIterator current_enemy;

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
void Engine::movePlayer(global_enums::Directions direction) {

  std::array<int,2> player_pos = player.getPosition();

  switch(direction) {
  case global_enums::NORTH:
    player_pos[1]++;
    player.move(player_pos);
    break;
  case global_enums::EAST :
    player_pos[0]++;
    player.move(player_pos);
    break;
  case global_enums::SOUTH:
    player_pos[1]--;
    player.move(player_pos);
    break;
  case global_enums::WEST:
    player_pos[0]--;
    player.move(player_pos);
    break;
  default:
    // Shouldn't be here!
    std::cout << "Not a valid direction\n";
    break;
  }
}
