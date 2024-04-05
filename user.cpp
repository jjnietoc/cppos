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
      createUser(database, users);
      break;
    }
    case 2: {
      modifyUser(database);
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

void createUser(SQL &database, std::vector<User> users) {
  std::cout << "Add new user?\n" <<
    "Press (1) for 'yes' and (2) for 'no': " << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 2) {
    std::cout << "Thank you! Bye!\n" << std::endl;
  } else {
    std::string userName;
    int admin;
    while(ans != 2 && !std::isalpha(ans)) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "User name: " << std::endl;
      std::getline(std::cin, userName);
      std::cout << "Is this user an admin?\nPress (1) for 'yes' and (2) for 'no'" << std::endl;
      std::cin >> admin;

      User user(userName, admin);

      users.push_back(user);

      std::cout << "User created.\nUser's code is: " << user.getPass() << std::endl;

      std::cout << "Would you like to add another user?\n" <<
        "Press (1) for 'yes' and (2) for 'no'" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> ans;
    }
  }
  if(users.empty()) {
    std::cout << "Bye!" << std::endl;
  } else {
    std::cout << "Would you like to add the following users to the database?:\n";
    std::cout << users;
  }

  for(int i = 0; i < users.size(); i++) {
    database.insertIntoTable("Users",
                             users[i].getName(),
                             users[i].getPass(),
                             users[i].getAdmin());
  }
}

void modifyUser(SQL &database) {
  std::string column, newval, name;
  std::cout << "UPDATE users\nFill in the following:\nColumn: " std::endl;
  std::cin.ignore();
  std::getline(std::cin, column);
  std::cout << "Name of product: " << std::endl;
  std::getline(std::cin, name);
  std::cout << "New value: " << std::endl;
  std::getline(std::cin, newval);
  std::cout << "You would like to update:\n" << name << ", in colum " <<
    column << " with " << newval << "\nPlease confirm with '1'" << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 1) {
    try {
      database.updateTable("USERS", column, newval, name);
    } catch(int error) {
      std::cin.clear();
      modifyUser(database);
    }
  } else {
    std::cout << "Bye!" << std::endl;
  }
}

void deleteUser(SQL &database) {

}

void checkUser(SQL &database) {

}
