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

  Room room1;

  // Create a new engine with the room to start in
  Engine engine(&room1);

  // Play the game!
  engine.play();

  return 0;
}
