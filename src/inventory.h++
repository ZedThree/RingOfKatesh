#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h++"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Inventory {
private:
  // Actual list of items in inventory
  ItemList item_list;

  // Find item in inventory, return ItemIterator to it
  // Only internal functions need these, to manipulate item_list vector
  // External functions will want the actual item
  ItemIterator findItemIterator(Item item_want); // Not needed?
  ItemIterator findItemIterator(std::string item_name);

public:

  Inventory() {};
  ~Inventory() {
    item_list.clear();
  };

  // Find item in inventory, return pointer to it
  Item* findItem(Item item_want);
  Item* findItem(std::string item_name);

  // Inventory manipulation funcs return number of items
  // actually added/removed
  // Add num_items of item to inventory
  int addItem(Item* item, int num_items);
  // Add item to inventory
  int addItem(Item* item);
  int removeItem(Item item, int num_items);

  // Return how many of item_name are in inventory
  int getNumItems(std::string item_name);

  // Print what items, and how many of them, are in inventory
  void printInventory();

  // Remove any items with count<=0
  void cleanupInventory();

};

#endif
