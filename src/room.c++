#include "room.h++"
#include "dice.h++"
#include "creature.h++"
#include "creature_types.h++"

// Randomly generate a new room
Room::Room() {

  doors = Exits(0,0,0,0);

  name = "A randomly generated room";

  description = "A small, dim and damp cave. A few flickering candle stumps provide the only light";

  Dice d20(20);

  // Random encounters
  if (d20.roll() > Kobold::ENCOUNTER_CHANCE) {
    enemies.push_back(Kobold());
  }
  if (d20.roll() > Rat::ENCOUNTER_CHANCE) {
    // Rats come in groups
    for (int ii = 0; ii < Dice(4).roll(); ++ii) {
      enemies.push_back(Rat());
    }
  }

}

void Room::enter(Player& player) {

  // Add this room to the player's map
  player.updateMap(doors);

  // Give a description of the room and the enemies in it
  printDescription();
  printEnemies();

}

// Print the description of the room
void Room::printDescription() {
  std::cout << description << std::endl;
}

// Print a list of the enemies here
void Room::printEnemies() {
  std::cout << "There are " << enemies.size() << " enemies here:\n";

  // The iterator for the list of enemies
  enemy_iterator current_enemy;

  // Iterate over list of enemies and announce their starting health
  current_enemy = enemies.begin();
  while (current_enemy != enemies.end()) {
    // build an intermediate string
    std::string enemy_announcement = current_enemy->getName() + " start health: ";
    std::cout << enemy_announcement << current_enemy->getHp() << "\n";
    current_enemy++;
  }
}
