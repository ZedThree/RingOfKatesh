#include "inventory.h++"

// Given an instance of an item, find another one in inventory
// Returns nullptr if none found
// ItemIterator Inventory::findItemIterator(Item* item_want) {

//   ItemIterator item_found = std::find(item_list.begin(),
// 				      item_list.end(),
// 				      item_want);

//   return item_found;
// }

// Given the name of an item, find it in inventory
ItemIterator Inventory::findItemIterator(std::string item_name) {

  ItemIterator item_found = std::find(item_list.begin(),
				      item_list.end(),
				      item_name);

  return item_found;
}

// Given an instance of an item, find another one in inventory
// Returns nullptr if none found
Item* Inventory::findItem(Item item_want) {

  ItemIterator item_found = findItemIterator(item_want.getName());

  return item_found != item_list.end() ? *item_found : nullptr;
}

// Given the name of an item, find it in inventory
// Returns nullptr if none found
Item* Inventory::findItem(std::string item_name) {

  ItemIterator item_found = findItemIterator(item_name);

  return item_found != item_list.end() ? *item_found : nullptr;
}

// Add num_items of item to inventory
int Inventory::addItem(Item* item, int num_items) {

  Item* item_old = findItem(*item);

  if (item_old) {
    // If the item is already in the inventory, then increase its count
    num_items = item_old->addItem(num_items);
  } else {
    // If the item is not in the inventory, then add it
    item_list.push_back(item);
  }
  return num_items;
}

// Add item to inventory
int Inventory::addItem(Item* item) {

  int num_items = addItem(item, item->getNumber());
  return num_items;

}

int Inventory::removeItem(Item item, int num_items) {

  ItemIterator item_old = findItemIterator(item.getName());

  if (item_old != item_list.end()) {
    // If the item is already in the inventory, then increase its count
    num_items = (*item_old)->removeItem(num_items);
    if ((*item_old)->getNumber() <= 0) {
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

  Item* item = findItem(item_name);

  if (item) {
    return item->getNumber();
  } else {
    return 0;
  }
}

void Inventory::printInventory() {

  for (auto item = item_list.begin(); item != item_list.end(); ++item) {
    std::cout << (*item)->getName() << ": " << (*item)->getNumber() << std::endl;
  }

}

// Remove any items with count<=0
void Inventory::cleanupInventory() {

  // std::remove_if - Remove all items that are empty.

  // This returns the new end of the vector, and leaves a gap between
  // this element and the actual end of the vector We then have to
  // erase all elements between that returned from remove_if and the
  // old end
  item_list.erase(std::remove_if(item_list.begin(),
				 item_list.end(),
				 isEmpty),
		  item_list.end());

}
