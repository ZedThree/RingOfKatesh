#include <cstdlib>
#include <ctime>

void startDice() {
    std::srand(std::time(0));
}

int die6() {
  return (std::rand() % 6) + 1;
}

int die4() {
  return (std::rand() % 4) + 1;
}
