#ifndef PLAYER_H
#define PLAYER_H

#include "item.h++"
#include <array>

class Player : public Creature {
private:
  typedef std::array<int,2> coords;

  // Coordinates in the map
  coords position = {{0, 0}};

public:
  Player() : Creature("player", 10, Dice(6, 2), Dice(6, 2)) {}

  coords getPosition() { return position; }

  void move(coords new_position ) { position = new_position; }

};


#endif
