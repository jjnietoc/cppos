// corp.cpp -- implementing corp functionalities

#include "corp.hpp"
#include "db.hpp"

User::User(const std::string & un, 
           bool ad) {
  setID();
  setName(un);
  setAdmin(ad);
}

User::~User() {}

void User::setID() {
  int temp = rand() % 9000 + 1000;
  ID = std::to_string(temp);
  }

void User::setName(const std::string &un) {
  username = un;
}

void User::setAdmin(bool ad) {
  isAdmin = ad;
}

void User::modifyUser(const std::string & n_user,
                 bool n_ad) {
  setName(n_user);
  setAdmin(n_ad);
}

std::ostream& operator<<(std::ostream& out, const std::vector<User>& v) {
    out << "List of users:\n";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << i + 1 << ") " << v[i].getName() << ". ID: "
    << v[i].getID() << ".";
        if(i != last)
          out << "\n"; 
        }
      out << "\n";
      return out;
}

void userLoop() {
  SQL database;

  database.openDB();

  std::string userTableName = "Users";

  database.createTable(userTableName, 3); // NOTE fix this

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
