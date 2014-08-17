#include "potion.h++"
#include "creature.h++"
#include <iostream>

// use the potion on creature
void Potion::use(Creature& creature) {
  int healed = creature.heal(healing);
  std::cout << "The " << creature.getName() << " heals " << healed << "hp\n";
  removeItem(1);
}
