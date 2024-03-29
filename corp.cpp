// corp.cpp -- implementing corp functionalities

#include "corp.hpp"
#include "db.hpp"

User::User(const std::string & un, 
           bool ad) {
  setPass();
  setName(un);
  setAdmin(ad);
}

User::~User() {}

void User::setPass() {
  int temp = rand() % 9000 + 1000;
  pass = std::to_string(temp);
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
    << v[i].getPass() << ".";
        if(i != last)
          out << "\n"; 
        }
      out << "\n";
      return out;
}
