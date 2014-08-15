#ifndef GLOBALS_H
#define GLOBALS_H

#include <array>

// Type for coordinates in dungeon/player map
typedef std::array<int,2> coords;

// Size of the dungeon
// Make this into an argument to the dungeon/player?
const int DUNGEON_DIMS = 3;

#endif
