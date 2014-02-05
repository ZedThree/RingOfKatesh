#include "dice.h++"
#include <cstdlib>

// Roll the dice
int Dice::Roll() {
  int result = 0;
  // Roll the dice once for each die in the object
  // and sum the results
  for (int ii = 0; ii < number; ii++) {
    result += (std::rand() % sides) + 1;
  }
  return result;
}
