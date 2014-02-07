#ifndef DICE_H
#define DICE_H

// A number of dice, all with the same number of sides
class Dice {
private:
  int sides;			// number of sides per die
  int number;			// number of dice

public:
  Dice() : sides(0), number(0) {}		//
  Dice(int s, int n) : sides(s), number(n) {}	// Construct a number of dice with sides

  int roll();		// Roll the dice

  int getSides() { return sides; }
  int getNumber() { return number; }

};

#endif
