#include "stock.hpp"
#include "user.hpp"

int main(void) {
  std::cout << "cpPOS v0.1.1\nSelect what interface to use:\nPress (1) for PRODUCTS or (2) for USERS" << std::endl;
  int ans;
  std::cin >> ans;
  switch(ans) {
    case 1: {
      stockLoop();
      break;
    }
    case 2: {
      userLoop();
      break;
    }
  }
  return 0;
}
