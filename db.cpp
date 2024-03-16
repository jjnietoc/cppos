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

void SQL::createAlcoholTable(std::string name) {
  //std::transform(name.begin(), name.end(), name.begin(), ::toupper);
  upper(name);
  std::string fullcmd = "CREATE TABLE " + name + " (" \
  "ID INTEGER     PRIMARY KEY," \
  "NAME           TEXT  NOT NULL," \
  "TYPE           TEXT  NOT NULL," \
  "VOLUME         TEXT  NOT NULL," \
  "PRICE          INT   NOT NULL," \
  "STOCK          INT   NOT NULL," \
  "SIZE           REAL  NOT NULL);";
  
  sql = fullcmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg << "\n";
    sqlite3_free(errMsg);
  } else {
    std::cout << "Operation done successfully\n";
  }
}

void SQL::insertIntoAlcohol(std::string tName,
                          std::string name, 
                          std::string type,
                          std::string volume,
                          int stock,
                          float price,
                          float size) {
  
  upper(tName);
  std::string insertcmd = 
    "INSERT INTO " + tName + " (NAME,TYPE,VOLUME,PRICE,STOCK,SIZE) " \
    "VALUES (" 
    + "'" + name + "'" + ", " 
    + "'" + type + "'" + ", " 
    + "'" + volume + "'" + ", " 
    + std::to_string(price) + ", " 
    + std::to_string(stock) + ", " 
    + std::to_string(size) + ");"; \
  sql = insertcmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg;
    sqlite3_free(errMsg);
  } else {
    std::cout << "Insert into alcohol done successfully\n";
  }
}

void SQL::insertIntoChips(std::string tName,
                          std::string name, 
                          int stock,
                          float price,
                          float size) {
  
  upper(tName);
  std::string insertcmd = 
    "INSERT INTO " + tName + " (NAME,TYPE,STOCK,PRICE,SIZE) " \
    "VALUES (" 
    + "'" + name + "'" + ", " 
    + std::to_string(stock) + ", " 
    + std::to_string(price) + ", " 
    + std::to_string(size) + ");"; \
  sql = insertcmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg << "\n";
    sqlite3_free(errMsg);
  } else {
    std::cout << "Insert into chips done successfully\n";
  }
}


void SQL::updateTable(std::string tName, 
                      std::string column, 
                      std::string newval, 
                      std::string name) {
  upper(tName);
  std::string updatecmd =
    "UPDATE " 
    + tName + " set " 
    + column + " = " 
    + "'" + newval + "'" 
    + "where NAME=" + "'" + name +  + "; "; \
  sql = updatecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg;
    sqlite3_free(errMsg);
  } else {
    std::cout << "Update done successfully\n";
  }
}

void SQL::deleteFromTable(std::string tName, std::string name) {
  upper(tName);
  std::string deletecmd = 
    "DELETE FROM " + tName + " WHERE NAME=" + name + ";"; \
  sql = deletecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg;
    sqlite3_free(errMsg);
  } else {
    std::cout << "Operation done successfully\n";
  }
}

void SQL::closeDataBase() {
  sqlite3_close(db);
}



