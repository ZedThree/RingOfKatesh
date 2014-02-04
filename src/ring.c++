#include <iostream>
#include "dice.h++"

int main() {
  startDice();

  for (int ii = 0; ii < 10; ii++) {
    std::cout << die4() << std::endl;
  }
  return 0;
}
