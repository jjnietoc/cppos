#include "stock.hpp"
#include "user.hpp"

int main(void) {
  std::cout << "cpPOS v0.1.1\n-------------\n" << 
    "Select what interface to use:\nPress (1) for STOCK or (2) for USERS or (3) for RETAIL" << std::endl;
  int ans;
  std::cin >> ans;
  switch(ans) {
    case 1: {
      // needs authentication
      stockLoop();
      break;
    }
    case 2: {
      userLoop();
      break;
    }
    case 3: {
      // needs authentication
      // retail
      break;
    }
  }
  return 0;
}
