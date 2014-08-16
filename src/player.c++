#include "player.h++"

// Print out the dungeon, with the current player
// position blinking
void Player::printMap() {

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

  Coords player_pos = getPosition();

  for (int y = DUNGEON_DIMS-1; y >= 0; y--) {
    for (int x = 0; x < DUNGEON_DIMS; ++x) {
      if (x == player_pos[0] && y == player_pos[1]) {
	printf("\033[5m");
      }
      std::cout << room_chars[map[x][y]];
      if (x == player_pos[0] && y == player_pos[1]) {
	printf("\033[m");
      }
    }
    std::cout << std::endl;
  }
}

void Player::updateMap(Exits doors) {
  Coords pos = getPosition();
  map[pos[0]][pos[1]] = doors;
}

// void Player::printInventory() {
//   Inventory::iterator current_item;

//   for (current_item = inventory.begin();
//        current_item != inventory.end();
//        ++current_item) {
//     std::cout << current_item->getName() << "\n";
//   }
// }
