#ifndef POTION_H
#define POTION_H

#include "item.h++"
#include "creature.h++"
#include <iostream>

class Potion : public Item {
private:
  const int healing = 5;

public:
  Potion(int num) : Item("Potion", "A healing potion. Heals 5hp", num) {}
  virtual ~Potion() {}
  void use(Creature& creature); 	// use the potion on creature

};

class Poison : public Item {
private:
  const int damage = 5;

public:
  Poison(int num) : Item("Poison", "A vile poison!", num) {}
  virtual ~Poison() {}
  void use(Creature& creature);
};

#endif
