#include "dice.h++"
#include <cstdlib>
#include <unistd.h>		// for usleep
#include <iostream>
#include <string>

// Set the name of the dice, e.g. 2d6
std::string Dice::setName() {
  std::string n = std::to_string(number);
  std::string s = std::to_string(sides);
  return n + "d" + s;
}

// Roll the dice
int Dice::roll() {
  int result = 0;
  // Roll the dice once for each die in the object
  // and sum the results
  for (int ii = 0; ii < number; ii++) {
    result += (std::rand() % sides) + 1;
  }
  return result;
}
