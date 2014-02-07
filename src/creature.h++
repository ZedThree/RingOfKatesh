#ifndef CREATURE_H
#define CREATURE_H

#include "dice.h++"

class Creature {
private:
  bool alive;
  int hp;			// number of hit points
  Dice attackDice;		// number and type of dice to roll for attacking
  Dice defendDice;		// number and type of dice to roll for defending

  Creature() {}			// no default creature

public:
  Creature(int h, Dice a, Dice d) : alive(true), hp(h), attackDice(a), defendDice(d) {} //

  void attack(Creature& enemy);	// attack an enemy
  int defend();			// roll the defend dice
  void takeDamage(int damage);	// lower hp
  int getHp() { return hp; }
  bool isAlive() { return alive; }
  void kill() { alive = false; }
};

#endif
