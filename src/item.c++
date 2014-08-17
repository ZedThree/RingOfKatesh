#include "item.h++"

// Returns number of items added to stack
int Item::addItem(int num) {
  count += num;
  if (count > max_count) {
    num -= count - max_count;
    count = max_count;
  }
  return num;
}

// Returns number of items removed from stack
int Item::removeItem(int num) {
  count -= num;
  if (count < 0) {
    num = count + num;
    count = 0;
  }
  return num;
}