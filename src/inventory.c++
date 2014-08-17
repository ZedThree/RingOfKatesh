#include "inventory.h++"

Inventory::ItemIterator Inventory::findItem(Item item_want) {
  // Iterator for item_list
  ItemIterator item_found = std::find(item_list.begin(),
				      item_list.end(),
				      item_want);

  return item_found;
}

Inventory::ItemIterator Inventory::findItem(std::string item_name) {
  ItemIterator item_found = std::find(item_list.begin(),
				      item_list.end(),
				      item_name);
  return item_found;
}

// Add num_items of item to inventory
int Inventory::addItem(Item item, int num_items) {

  ItemIterator item_old = findItem(item);

  if (item_old != item_list.end()) {
    // If the item is already in the inventory, then increase its count
    num_items = item_old->addItem(num_items);
  } else {
    // If the item is not in the inventory, then add it
    item_list.push_back(item);
  }
  return num_items;
}

// Add item to inventory
int Inventory::addItem(Item item) {

  int num_items = addItem(item, item.getNumber());
  return num_items;

}

int Inventory::removeItem(Item item, int num_items) {

  ItemIterator item_old = findItem(item);

  if (item_old != item_list.end()) {
    // If the item is already in the inventory, then increase its count
    num_items = item_old->removeItem(num_items);
    if (item_old->getNumber() <= 0) {
      item_list.erase(item_old);
    }
  } else {
    // If the item is not in the inventory, then we can't remove any!
    num_items = 0;
  }
  return num_items;
}

// Return how many of item_name are in inventory
int Inventory::getNumItems(std::string item_name) {

  ItemIterator item = findItem(item_name);

  if (item != item_list.end()) {
    return item->getNumber();
  } else {
    return 0;
  }
}

void Inventory::printInventory() {

  for (auto item = item_list.begin(); item != item_list.end(); ++item) {
    std::cout << item->getName() << ": " << item->getNumber() << std::endl;
  }
  std::cout << "\n";

}
