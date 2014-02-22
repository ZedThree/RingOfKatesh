#ifndef POTION_H
#define POTION_H

#include "item.h++"
#include "creature.h++"
#include <iostream>

class Potion : public Item {
private:
  const int healing = 5;

public:
  Potion() : Item("Potion", "A healing potion. Heals 5hp") {}
  virtual ~Potion() {}
  void use(Creature& creature); 	// use the potion on creature

};

#endif
