#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
private:
  std::string name;		// name of the item
  std::string description;	// a short description

  Item() {}			// no default item

public:
  Item(std::string n, std::string d) :
    name(n), description(d) {}

  // getters
  std::string getName() { return name; }
  std::string getDescription() { return description; }

  virtual void use() {
    std::cout << "You cannot use this item\n";
  }
};

#endif
