#include "exits.h++"

unsigned int Exits::calcValue(bool north, bool east, bool south, bool west) {
  unsigned int value = 0;
  if (north) {
    value |= 8;
  }
  if (east) {
    value |= 4;
  }
  if (south) {
    value |= 2;
  }
  if (west) {
    value |= 1;
  }

  return value;
}

void Exits::setNorth(bool n) {
  north = n;
  if(n) {
    value |= 1 << 3;
  } else {
    value &= ~(1 << 3);
  }
}
void Exits::setEast(bool e) {
  east = e;
  if(e) {
    value |= 1 << 2;
  } else {
    value &= ~(1 << 2);
  }
}
void Exits::setSouth(bool s) {
  south = s;
  if(s) {
    value |= 1 << 1;
  } else {
    value &= ~(1 << 1);
  }
}
void Exits::setWest(bool w) {
  west = w;
  if(w) {
    value |= 1 << 0;
  } else {
    value &= ~(1 << 0);
  }
}

int Exits::getNumExits() {

  int num = 0;

  num += north ? 1 : 0;
  num += east  ? 1 : 0;
  num += south ? 1 : 0;
  num += west  ? 1 : 0;

  return num;

}
