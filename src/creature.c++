#include "dice.h++"
#include "creature.h++"
#include <iostream>

void Creature::attack(Creature& enemy) {
  int damage = this->attackDice.roll() - enemy.defend();
  if (damage > 0) {
    std::cout << "You do " << damage << " hp of damage to the kobold\n";
    enemy.takeDamage(damage);
  }
}

int Creature::defend() {
  return this->defendDice.roll();
}

void Creature::takeDamage(int damage) {
  hp -= damage;
  if (hp <= 0) {
    kill();
  }
}
