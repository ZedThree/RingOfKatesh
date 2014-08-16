#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
private:
  std::string name;		// Name of the item
  std::string description;	// Short description
  int count;			// Number of items in stack
  int max_count;		// Max items in stack

  Item() {}			// no default item

public:
  Item(std::string n, std::string d, int num) :
    name(n), description(d), count(num) {}

  virtual ~Item() {}

  // getters
  std::string getName() { return name; }
  std::string getDescription() { return description; }
  int getNumber() { return count; }

  // setters
  int addItem(int num);		// Add item to stack
  int removeItem(int num);	// Remove item from stack

  // interactions
  virtual void use() {
    std::cout << "You cannot use this item\n";
  }
};

#endif
