#ifndef DICE_H
#define DICE_H

// A number of dice, all with the same number of sides
class Dice {
private:
  int sides;			// number of sides per die
  int number;			// number of dice

  Dice() {}			// No default die

public:
  Dice(int s, int n) : sides(s), number(n) {}	// Construct a number of dice with sides

  int Roll();		// Roll the dice

  int GetSides() { return sides; }
  int GetNumber() { return number; }

};


#endif
