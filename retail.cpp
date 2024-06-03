#include "retail.hpp"

void addToCart() {
  // necesita tener algun requerimiento porque sino como meto cosas
}

int change(int a, int b) {
  uint total = a - b;
  return total;
}

void selectItem() {

}

// NOTE this should be a search function that looks into all tables, without the need to give it one
void searchItem(SQL &database) {
  std::string tn, en;
  std::cout << "Product table: " << std::endl;
  std::cin >> tn;
  std::cout << "Item name: " << std::endl;
  std::cin >> en;
  database.findEntryInTable(tn, en);
}

void transformToVector(SQL &database) {

}



