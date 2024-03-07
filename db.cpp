#include "db.hpp"
#include <algorithm>

SQL::SQL() {

}

SQL::~SQL() {

}

int SQL::openDB() {
  rc = sqlite3_open("corp.db", &db);
  if(rc) {
    std::cout << "Can't open database:\n" << sqlite3_errmsg(db);
    return 0;
  } else {
    std::cout << "Opened database successfully\n";
    return 1;
  }
}

void SQL::createTable(std::string name) {
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  std::string fullcmd = "CREATE TABLE " + name + "(" \
  "ID INT PRIMARY KEY   AUTOINCREMENT," \
  "NAME           TEXT  NOT NULL," \
  "TYPE           TEXT  NOT NULL," \
  "VOLUME         TEXT  NOT NULL," \
  "PRICE          INT   NOT NULL," \
  "STOCK          INT   NOT NULL," \
  "SIZE           REAL  NOT NULL);";
  
  sql = fullcmd;
//  std::strncpy(sql, fullcmd.c_str(), sizeof(sql) - 1);
//  std::cout << sql;
}

void SQL::insertIntoTable(std::string name, 
                          std::string type,
                          std::string volume,
                          int price,
                          int stock,
                          float size) {

}

void SQL::updateTable(std::string column, std::string newval) {

}

void SQL::deleteFromTable(std::string name) {

}
