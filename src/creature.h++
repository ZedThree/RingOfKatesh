#ifndef CREATURE_H
#define CREATURE_H

#include "dice.h++"
#include <string>

class Creature {
private:
  std::string name;	// creature name
  bool alive;
  int maxhp;		// maximum number of hit points
  int hp;		// current number of hit points
  Dice attackDice;	// number and type of dice to roll for attacking
  Dice defendDice;	// number and type of dice to roll for defending

  Creature() {}		// no default creature

public:
  Creature(std::string n, int maxh, Dice a, Dice d) :
    name(n), alive(true), maxhp(maxh), hp(maxh), attackDice(a), defendDice(d) {} //

  // getters
  std::string getName() { return name; }

  bool isAlive() { return alive; }

  int getHp() { return hp; }

  std::string getAttackDiceName() { return attackDice.getName(); } // get the name of the attack dice, e.g. 2d6
  std::string getDefendDiceName() { return defendDice.getName(); } // get the name of the defend dice

  // setters
  void kill() { alive = false; } // mark the creature as dead

  int takeDamage(int damage);	 // lower hp
  int heal(int healing);	 // raise hp (upto maxhp)

  // interactions
  void attack(Creature& target); // attack an target

  int defend();			 // roll the defend dice
  int printDefend() { return defendDice.printRoll(); } // roll the defend dice and show them on screen
};

#endif
