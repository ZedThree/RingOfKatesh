#include "dice.h++"
#include "creature.h++"
#include <iostream>
#include <string>

// Attack a creature
void Creature::attack(Creature& target) {

  // First, roll the attack dice for this creature
  std::cout << "The " << this->getName() << " rolls " << getAttackDiceName() << "\n";
  int attack_result = attackDice.printRoll();
  std::cout << "A " << attack_result << "!\n";

  // then roll the defence dice for the target
  std::cout << "The " << target.getName() << " rolls " << target.getDefendDiceName() << "\n";
  int defence_result = target.printDefend();
  std::cout << "A " << defence_result << "!\n\n";

  // If the attacker rolled higher than the defender, then deal that as damage
  int damage = attack_result - defence_result;
  if (damage > 0) {
    std::cout << "A hit!\n";
    damage = target.takeDamage(damage);
  }
  if (damage > 0) {
    std::cout << "The " << this->getName() << " does " << damage << " hp of damage to the "
	      << target.getName() << "\n\n";

  } else {
    std::cout << "A miss!\n\n";
  }
}

// Roll the defend dice
int Creature::defend() {
  return this->defendDice.roll();
}

// Deal damage to the creature
// Return actual damage dealt
int Creature::takeDamage(int damage) {
  hp -= damage;
  if (hp <= 0) {
    alive = false;
    // kill();
  }
  return damage;
}

// Heal the creature, up to maxhp
// Returns actual amount healed
int Creature::heal(int healing) {
  hp += healing;
  if (hp > maxhp) {
    healing -= hp-maxhp;
    hp = maxhp;
  }
  return healing;
}
