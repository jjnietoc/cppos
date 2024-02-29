#include "db.hpp"

int SQL::openDB() {
  rc = sqlite3_open("corp.hpp", &db);
  if(rc) {
    std::cout << "Can't open database:\n" << sqlite3_errmsg(db);
    return 0;
  } else {
    std::cout << "Opened database successfully\n";
    return 1;
  }
}

void SQL::createTable(std::string name) {
  sql = "CREATE TABLE BUSINESS(" \
  "ID INT PRIMARY KEY   AUTOINCREMENT," \
  "NAME           TEXT  NOT NULL," \
  "TYPE           TEXT  NOT NULL," \
  "VOLUME         TEXT  NOT NULL," \
  "PRICE          INT   NOT NULL," \
  "STOCK          INT   NOT NULL," \
  "SIZE           REAL  NOT NULL);";
}
