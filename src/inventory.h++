#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h++"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Inventory {
private:
  // Map of item names and number of items
  typedef std::vector<Item> ItemList;

  // Actual list of items in inventory
  ItemList item_list;

public:
  // Iterator over item_list
  typedef ItemList::iterator ItemIterator;

  Inventory() {};
  ~Inventory() {};

  // Find item in inventory, return pointer to it
  ItemIterator findItem(Item item_want);
  ItemIterator findItem(std::string item_name);

  // Inventory manipulation funcs return number of items
  // actually added/removed
  // Add num_items of item to inventory
  int addItem(Item item, int num_items);
  // Add item to inventory
  int addItem(Item item);
  int removeItem(Item item, int num_items);

  // Return how many of item_name are in inventory
  int getNumItems(std::string item_name);

  void printInventory();

};

#endif
