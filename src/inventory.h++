#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h++"
#include <map>
#include <pair>
#include <string>
#include <vector>

class Inventory {
private:
  // Map of item names and number of items
  typedef std::map<std::string, int> ItemList;
  // Pair of item names and number of items for map insertion
  typedef std::pair<std::string, int> ItemNum;
  // Actual list of items in inventory
  ItemList item_list;

public:
  Inventory() {};
  ~Inventory() {};

  // Add num_items of item to inventory
  void addItem(Item* item, int num_items) {
    item_list.insert(ItemNum(item.getName(), num_items));
  }

  // Return how many of item_name are in inventory
  int getNumItems(std::string item_name) {
    return item_list[item_name];
  }

};

#endif
