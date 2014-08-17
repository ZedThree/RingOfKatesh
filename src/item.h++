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

  //

  Item() {}			// no default item

public:
  Item(std::string n, std::string d, int num) :
    name(n), description(d), count(num) {}

  virtual ~Item() {}

  // getters
  std::string getName() { return name; }
  std::string getName() const { return name; }
  std::string getDescription() { return description; }
  int getNumber() { return count; }

  // setters
  int addItem(int num);		// Add item to stack
  int removeItem(int num);	// Remove item from stack

  // interactions
  virtual void use() {
    std::cout << "You cannot use this item\n";
  }

  // Arithmetic operators
  Item& operator+=(const Item& rhs) {
    addItem(rhs.count);
    return *this;
  }

  Item& operator-=(const Item& rhs) {
    removeItem(rhs.count);
    return *this;
  }

};

// Arithmetic operators
inline Item operator+(Item lhs, const Item& rhs) {
  lhs += rhs;
  return lhs;
}

inline Item operator-(Item lhs, const Item& rhs) {
  lhs -= rhs;
  return lhs;
}

// Comparison operators
inline bool operator==(const Item& lhs, const Item& rhs) {
  return (lhs.getName() == rhs.getName());
}

inline bool operator!=(const Item& lhs, const Item& rhs) {
  return !operator==(lhs,rhs);
}

inline bool operator< (const Item& lhs, const Item& rhs) {
  return (lhs.getName() < rhs.getName());
};

inline bool operator> (const Item& lhs, const Item& rhs) {
  return operator<(rhs, lhs);
};

inline bool operator<=(const Item& lhs, const Item& rhs) {
  return !operator>(rhs, lhs);
};

inline bool operator>=(const Item& lhs, const Item& rhs) {
  return !operator<(rhs, lhs);
};

// Comparison with string
inline bool operator==(const Item& lhs, const std::string rhs) {
  return (lhs.getName() == rhs);
}

inline bool operator!=(const Item& lhs, const std::string rhs) {
  return !operator==(lhs,rhs);
}



#endif
