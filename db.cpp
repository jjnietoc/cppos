#include "db.hpp"
#include <algorithm>

SQL::SQL() {

}

SQL::~SQL() {

}

std::string SQL::upper(std::string name) {
  std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  return name;
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
  //std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  upper(name);
  std::string fullcmd = "CREATE TABLE " + name + " (" \
  "ID INT PRIMARY KEY   AUTOINCREMENT," \
  "NAME           TEXT  NOT NULL," \
  "TYPE           TEXT  NOT NULL," \
  "VOLUME         TEXT  NOT NULL," \
  "PRICE          INT   NOT NULL," \
  "STOCK          INT   NOT NULL," \
  "SIZE           REAL  NOT NULL);";
  
  sql = fullcmd;
//  std::cout << sql;
}

void SQL::insertIntoTable(std::string tName,
                          std::string name, 
                          std::string type,
                          std::string volume,
                          int price,
                          int stock,
                          float size) {
  
  upper(tName);
  std::string tablecmd = 
    "INSERT INTO " + tName + " (NAME,TYPE,VOLUME,PRICE,STOCK,SIZE) " \
    "VALUES (" + name + ", " + type + ", " + volume + ", " + price + ", " + stock + ", " + size + ")";
  
}

void SQL::updateTable(std::string column, std::string newval) {

}

void SQL::deleteFromTable(std::string name) {

}


