#include "dungeon.h++"

Dungeon::Dungeon() {
  map.resize(boost::extents[DUNGEON_DIMS][DUNGEON_DIMS]);

  // Initialise the dungeon with random rooms
  for (int x = 0; x < DUNGEON_DIMS; ++x) {
    for (int y = 0; y < DUNGEON_DIMS; ++y) {
      map[x][y] = Room();
    }
  }

  // Generate map like spelunky

  // Pick random coords on southern edge for start_room
  int x = (std::rand() % DUNGEON_DIMS);
  int y = 0;

  start_room[0] = x;
  start_room[1] = y;

  Directions dir;			// Direction we're going to move

  bool no_exit = true;		// No ring room exists yet

  do {
    int new_dir = pickDir();

    // Pick direction (east, west, south)
    switch(new_dir) {
    case 1:
    case 2:
      dir = Directions::EAST;
      break;
    case 3:
    case 4:
      dir = Directions::WEST;
      break;
    case 5:
      dir = Directions::NORTH;
      break;
    }

    // Check if we've hit the dungeon's walls!
    // If we have, set direction to north
    if (dir == Directions::EAST && x == DUNGEON_DIMS - 1) {
      dir = Directions::NORTH;
    } else if (dir == Directions::WEST && x == 0) {
      dir = Directions::NORTH;
    } else if (dir == Directions::NORTH && y == DUNGEON_DIMS - 1) {
      // Place ring here
      no_exit = false;
    }

    // Place an East-West corridor in this room
    map[x][y].doors.setEast(true);
    map[x][y].doors.setWest(true);

    // If we picked east or west that's ok

    // If we picked north, give it a north door
    if (dir == Directions::NORTH) {
      map[x][y].doors.setNorth(true);
    }

    // If we moved here from the south, add a south door
    if (y >=1 && map[x][y-1].doors.getNorth()) {
      map[x][y].doors.setSouth(true);
    }

    // If we're at the edge, turn off those walls
    if (x == 0) {
      map[x][y].doors.setWest(false);
    } else if (x == DUNGEON_DIMS-1) {
      map[x][y].doors.setEast(false);
    }
    if (y == 0) {
      map[x][y].doors.setSouth(false);
    } else if (y == DUNGEON_DIMS-1) {
      map[x][y].doors.setNorth(false);
    }

    // Connect to adjacent rooms
    if (x-1 >= 0) {
      map[x-1][y].doors.setEast(true);
    }
    if (x+1 <= DUNGEON_DIMS-1) {
      map[x+1][y].doors.setWest(true);
    }

    if ((x==0 || x==DUNGEON_DIMS-1) && y==DUNGEON_DIMS-1) {
      no_exit = false;
    }

    // Move to direction we picked
    switch(dir) {
    case Directions::NORTH :
      ++y;
      break;
    case Directions::EAST :
      ++x;
      break;
    case Directions::WEST :
      --x;
      break;
    default:
      std::cerr << "Shouldn't have reached here!\n";
      break;
    }

    // Pick a new direction
  } while (no_exit);

}

// Check whether it's possible to move in direction from position
bool Dungeon::movePossible(Coords position,
			   global_enums::Directions direction) {

  int x = position[0];
  int y = position[1];

  switch(direction) {
  case global_enums::NORTH :
    return map[x][y].doors.getNorth();
  case global_enums::EAST :
    return map[x][y].doors.getEast();
  case global_enums::SOUTH :
    return map[x][y].doors.getSouth();
  case global_enums::WEST :
    return map[x][y].doors.getWest();
  }
  return false;
}

// Return a pointer to the room at position
Room* Dungeon::getRoom(Coords position) {
  return &map[position[0]][position[1]];
}

// Print out the dungeon, with the current player
// position blinking
void Dungeon::printDungeon(Coords player_pos) {

  room_chars.insert(std::make_pair(Exits(0,0,0,0), "?"));
  room_chars.insert(std::make_pair(Exits(0,0,0,1), "╕"));
  room_chars.insert(std::make_pair(Exits(0,0,1,0), "╓"));
  room_chars.insert(std::make_pair(Exits(0,0,1,1), "╗"));
  room_chars.insert(std::make_pair(Exits(0,1,0,0), "╘"));
  room_chars.insert(std::make_pair(Exits(0,1,0,1), "═"));
  room_chars.insert(std::make_pair(Exits(0,1,1,0), "╔"));
  room_chars.insert(std::make_pair(Exits(0,1,1,1), "╦"));
  room_chars.insert(std::make_pair(Exits(1,0,0,0), "╙"));
  room_chars.insert(std::make_pair(Exits(1,0,0,1), "╝"));
  room_chars.insert(std::make_pair(Exits(1,0,1,0), "║"));
  room_chars.insert(std::make_pair(Exits(1,0,1,1), "╣"));
  room_chars.insert(std::make_pair(Exits(1,1,0,0), "╚"));
  room_chars.insert(std::make_pair(Exits(1,1,0,1), "╩"));
  room_chars.insert(std::make_pair(Exits(1,1,1,0), "╠"));
  room_chars.insert(std::make_pair(Exits(1,1,1,1), "╬"));

  std::cout << "\n";

  for (int y = DUNGEON_DIMS-1; y >= 0; y--) {
    for (int x = 0; x < DUNGEON_DIMS; ++x) {
      if (x == player_pos[0] && y == player_pos[1]) {
	printf("\033[5m");
      }
      std::cout << room_chars[map[x][y].doors];
      if (x == player_pos[0] && y == player_pos[1]) {
	printf("\033[m");
      }
    }
    std::cout << std::endl;
  }

}

// Print out the dungeon
void Dungeon::printDungeon() {

  room_chars.insert(std::make_pair(Exits(0,0,0,0), "?"));
  room_chars.insert(std::make_pair(Exits(0,0,0,1), "╕"));
  room_chars.insert(std::make_pair(Exits(0,0,1,0), "╓"));
  room_chars.insert(std::make_pair(Exits(0,0,1,1), "╗"));
  room_chars.insert(std::make_pair(Exits(0,1,0,0), "╘"));
  room_chars.insert(std::make_pair(Exits(0,1,0,1), "═"));
  room_chars.insert(std::make_pair(Exits(0,1,1,0), "╔"));
  room_chars.insert(std::make_pair(Exits(0,1,1,1), "╦"));
  room_chars.insert(std::make_pair(Exits(1,0,0,0), "╙"));
  room_chars.insert(std::make_pair(Exits(1,0,0,1), "╝"));
  room_chars.insert(std::make_pair(Exits(1,0,1,0), "║"));
  room_chars.insert(std::make_pair(Exits(1,0,1,1), "╣"));
  room_chars.insert(std::make_pair(Exits(1,1,0,0), "╚"));
  room_chars.insert(std::make_pair(Exits(1,1,0,1), "╩"));
  room_chars.insert(std::make_pair(Exits(1,1,1,0), "╠"));
  room_chars.insert(std::make_pair(Exits(1,1,1,1), "╬"));

  std::cout << "\n";

  for (int y = DUNGEON_DIMS-1; y >= 0; y--) {
    for (int x = 0; x < DUNGEON_DIMS; ++x) {
      std::cout << room_chars[map[x][y].doors];
    }
    std::cout << std::endl;
  }

}
