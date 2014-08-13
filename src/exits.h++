#ifndef EXITS_H
#define EXITS_H

class Exits {
private:
  bool north;
  bool east;
  bool south;
  bool west;

  // Array of bits for boost::multi_array
  // We need something to make comparisons
  unsigned int value;

  // Calculate the bit array
  unsigned int calcValue(bool n, bool e, bool s, bool w);

public:

  Exits() {}

  Exits(bool n, bool e, bool s, bool w) :
    north(n), east(e), south(s), west(w),
    value(calcValue(n, e, s, w)) {}

  // Copy constructor
  Exits(const Exits& other) :
    north(other.north),
    east(other.east),
    south(other.south),
    west(other.west),
    value(calcValue(north, east, south, west)) {}

  // Setters - set bool and set/reset corresponding
  // bit in value
  // No setter for value - it is automatically updated
  // by these functions
  void setNorth(bool n);
  void setEast(bool e);
  void setSouth(bool s);
  void setWest(bool w);

  bool getNorth() const { return north; }
  bool getEast()  const { return east;  }
  bool getSouth() const { return south; }
  bool getWest()  const { return west;  }
  unsigned int getValue() const { return value; }

  // Return the number of exits
  int getNumExits();

};

// Comparison operators, needed for boost::multi_array
inline bool operator==(const Exits& lhs, const Exits& rhs) {
  return (lhs.getValue() == rhs.getValue());
}

inline bool operator!=(const Exits& lhs, const Exits& rhs) {
  return !operator==(lhs,rhs);
}

inline bool operator< (const Exits& lhs, const Exits& rhs) {
  return (lhs.getValue() < rhs.getValue());
};

inline bool operator> (const Exits& lhs, const Exits& rhs) {
  return operator<(rhs, lhs);
};

inline bool operator<=(const Exits& lhs, const Exits& rhs) {
  return !operator>(rhs, lhs);
};

inline bool operator>=(const Exits& lhs, const Exits& rhs) {
  return !operator<(rhs, lhs);
};

#endif
