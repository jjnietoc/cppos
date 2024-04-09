// header file for user creation
#ifndef USER_HPP
#define USER_HPP

#include "corp.hpp"
#include "db.hpp"

void userLoop();

void createUser(SQL &database, std::vector<User>users);
void modifyUser(SQL &database);
void deleteUser(SQL &database);
void checkUser(SQL &database);

#endif
