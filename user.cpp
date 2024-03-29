#include "user.hpp"

void userLoop() {
  SQL database;

  database.openDB();

  std::string userTableName = "Users";

  database.createTable(userTableName, 3); 

  std::vector<User> users;
  
  std::cout << "\ncpPOS v 0.1\n-------------\nUser Interface\n" <<
    "-------------\nSelect from following (press number):\n" <<
    "(1) CREATE user.\n(2) MODIFY user.\n(3) DELETE user.\n(4) CHECK user.\n" << 
    std::endl;
  int response;
  std::cin >> response;
  switch(response) {
    case 1: {
      break;
    }
    case 2: {
      break;
    }
    case 3: {
    break;
    }
    case 4: {
    break;
    }
  }
}
