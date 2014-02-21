#include "dice.h++"
#include <cstdlib>
#include <unistd.h>		// for usleep
#include <iostream>
#include <string>

#define NUM_ROLLS 60		// how many times to roll the dice

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

// Roll the dice and print the results
int Dice::printRoll() {
  int total_result = 0;
  int* result = new int[number];

  int pause;
  for (int ii = 1; ii < NUM_ROLLS; ii++) {
    std::cout << "\r";

    for (int die = 0; die < number; die++) {
      result[die] = (std::rand() % sides) + 1;
      std::cout << " " << result[die] ;
    }
    std::cout.flush();

    pause = 50 * ii * ii;
    usleep(pause);
  }
  std::cout << "\n";

  for (int die = 0; die < number; die++) {
    total_result += result[die];
  }

  delete[] result;

  return total_result;
}
