#ifndef CREATURETYPES_H
#define CREATURETYPES_H

#include "creature.h++"
#include "dice.h++"

// Define some common creatures

class Kobold : public Creature {
public:
  Kobold() : Creature("kobold", 2 + Dice(6).roll(), Dice(4, 3), Dice(4, 2)) {}
};

class Rat : public Creature {
public:
  Rat() : Creature("rat", 1 + Dice(4).roll(), Dice(4), Dice(4)) {};
};

#endif
