#ifndef DICE_H
#define DICE_H

#include <string>

// A number of dice, all with the same number of sides
class Dice {
private:
  int sides;			// number of sides per die
  int number;			// number of dice
  std::string name;		// name of the dice showing the number and sides, e.g. 2d6

public:
  Dice() : sides(0), number(0), name(setName()) {}		//
  Dice(int s) : sides(s), number(1), name(setName()) {}		// Construct a single die with sides
  Dice(int s, int n) : sides(s), number(n), name(setName()) {}	// Construct a number of dice with sides

  int roll();		// Roll the dice
  int printRoll();	// Roll the dice and print the result to screen

  int getSides()	{ return sides;  }
  int getNumber()	{ return number; }
  std::string getName() { return name;   }

  std::string setName();	// set the name of the dice

};

#endif
