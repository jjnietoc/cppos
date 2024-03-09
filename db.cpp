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

static int callback(void *data, int argc, char **argv, char **azColName) {
  int i;
  for(i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  std::cout << "\n";
  return 0;
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
  std::string insertcmd = 
    "INSERT INTO " + tName + " (NAME,TYPE,VOLUME,PRICE,STOCK,SIZE) " \
    "VALUES (" 
    + name + ", " 
    + type + ", " 
    + volume + ", " 
    + std::to_string(price) + ", " 
    + std::to_string(stock) + ", " 
    + std::to_string(size) + "); "; \
  sql = insertcmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
}

void SQL::updateTable(std::string tName, std::string column, std::string newval, std::string name) {
  upper(tName);
  std::string updatecmd =
    "UPDATE " 
    + tName + " set " 
    + column + " = " 
    + newval + "where NAME=" 
    + name + "; "; \
  sql = updatecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
}

void SQL::deleteFromTable(std::string tName, std::string name) {
  upper(tName);
  std::string deletecmd = 
    "DELETE FROM " + tName + " WHERE NAME=" + name + ";"; \
  sql = deletecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
}



