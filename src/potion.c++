#include "potion.h++"
#include "creature.h++"
#include <iostream>

// use the potion on creature
void Potion::use(Creature& creature) {
  creature.heal(healing);
  std::cout << "The " << creature.getName() << " heals " << healing << "hp\n";
}
