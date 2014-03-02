#include "room.h++"

void Room::enter() {

  // Print the description of the room
  std::cout << description << std::endl;

  // Print a list of the enemies here
  std::cout << "There are " << enemies.size() << " enemies here:\n";

  // The iterator for the list of enemies
  std::vector<Creature>::iterator current_enemy;

  // Iterate over list of enemies and announce their starting health
  current_enemy = enemies.begin();
  while (current_enemy != enemies.end()) {
    // build an intermediate string
    std::string enemy_announcement = current_enemy->getName() + " start health: ";
    std::cout << enemy_announcement << current_enemy->getHp() << "\n";
    current_enemy++;
  }

}
