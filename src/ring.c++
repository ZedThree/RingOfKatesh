#include "dice.h++"
#include "creature.h++"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

  // Initialise the random number generator
  std::srand(std::time(0));

  // Dice player(6, 2);		// The dice for the player
  // Dice enemy(4, 3);		// The dice for the opponent

  // int player_hp = 5;
  // int enemy_hp = 4;

  int fight_choice;

  Creature player(5, Dice(6, 2), Dice(6, 2));
  Creature kobold(4, Dice(4, 3), Dice(4, 2));

  std::cout << "Your start health: " << player.getHp() << std::endl;
  std::cout << "Kobold start health: " << kobold.getHp() << std::endl;

  do {
    std::cout << "You attack the kobold\n";
    player.attack(kobold);
    std::cout << "Kobold health: " << kobold.getHp() << std::endl;
    std::cout << "The kobold attacks you\n";
    kobold.attack(player);
    std::cout << "Your health: " << player.getHp() << std::endl;

  } while (player.isAlive() && kobold.isAlive() );

  // std::cout << "You encounter a kobold!\n";
  // do {
  //   std::cout << "Your hp is " << player_hp << std::endl;
  //   do {
  //     std::cout << "Do you want to fight? 1 for yes, 0 for no\n";
  //     std::cin >> fight_choice;
  //   } while (fight_choice != 1 && fight_choice != 0);
  //   if (fight_choice == 0){
  //     break;
  //   }
  //   if (player.Roll() > enemy.Roll()) {
  //     std::cout << "You hit the kobold!\n";
  //     enemy_hp--;
  //   } else {
  //     std::cout << "The kobold hits you!\n";
  //     player_hp--;
  //   }
  // } while (player_hp > 0 && enemy_hp > 0);

  if (player.isAlive()) {
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }

  return 0;
}
