#include "engine.h++"
#include "room.h++"
#include "creature.h++"
#include "creature_types.h++"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

int main() {

  // Initialise the random number generator
  std::srand(std::time(0));

  // Set up the room. This should be moved to a map generator type thing
  std::string room1_desc;
  room1_desc = "A small, dim and damp cave. A few flickering candle stumps provide the only light";
  // All the enemies in this room
  std::vector<Creature> room1_creature_list;
  Kobold kobold;
  Rat rat;
  room1_creature_list.push_back(kobold);
  room1_creature_list.push_back(rat);
  // Make the room
  Room room1("start", room1_desc, room1_creature_list);

  // Create a new engine with the room to start in
  Engine engine(&room1);

  // Some initial set up
  engine.start();

  // Play the game!
  engine.play();

  return 0;
}
