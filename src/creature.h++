#ifndef CREATURE_H
#define CREATURE_H

#include "dice.h++"
#include <string>

class Creature {
private:
  std::string name;		// creature name
  bool alive;
  int hp;			// number of hit points
  Dice attackDice;		// number and type of dice to roll for attacking
  Dice defendDice;		// number and type of dice to roll for defending

  Creature() {}			// no default creature

public:
  Creature(std::string n, int h, Dice a, Dice d) :
    name(n), alive(true), hp(h), attackDice(a), defendDice(d) {} //

  // getters
  std::string getName() { return name; }

  bool isAlive() { return alive; }

  int getHp() { return hp; }

  std::string getAttackDiceName() { return attackDice.getName(); } // get the name of the attack dice, e.g. 2d6
  std::string getDefendDiceName() { return defendDice.getName(); } // get the name of the defend dice

  // setters
  void kill() { alive = false; } // mark the creature as dead

  void takeDamage(int damage);	 // lower hp

  // interactions
  void attack(Creature& target); // attack an target

  int defend();			 // roll the defend dice
  int printDefend() { return defendDice.printRoll(); } // roll the defend dice and show them on screen
};

#endif
