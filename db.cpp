#include "db.hpp"
#include <algorithm>
#include <map>

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

void SQL::createTable(std::string tName, int type) {
  switch(type) {
    case 1: {
      upper(tName);
      std::string fullcmd = "CREATE TABLE " + tName + " (" \
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
      break;
    }
    case 2: {
      upper(tName);
      std::string fullcmd2 = "CREATE TABLE " + tName + " (" \
      "ID INTEGER     PRIMARY KEY," \
      "NAME           TEXT  NOT NULL," \
      "STOCK          INT  NOT NULL," \
      "PRICE          INT   NOT NULL," \
      "SIZE           REAL  NOT NULL);";
  
      sql = fullcmd2;
      rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
      if(rc != SQLITE_OK) {
       std::cout << "SQL error:\n" << errMsg << "\n";
        sqlite3_free(errMsg);
      } else {
        std::cout << "Operation done successfully\n";
      }
      break;
    }
    case 3: {
      upper(tName);
      std::string fullcmd3 = "CREATE TABLE " + tName + " (" \
      "ID INTEGER     PRIMARY KEY," \
      "NAME           TEXT  NOT NULL," \
      "PASS           TEXT  NOT NULL," \
      "ADMIN          INT   NOT NULL);";
  
      sql = fullcmd3;
      rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
      if(rc != SQLITE_OK) {
       std::cout << "SQL error:\n" << errMsg << "\n";
        sqlite3_free(errMsg);
      } else {
        std::cout << "Operation done successfully\n";
      }
      break;
    }
  }
}

// alcohol
void SQL::insertIntoTable(std::string tName,
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

// chips
void SQL::insertIntoTable(std::string tName,
                          std::string name, 
                          int stock,
                          float price,
                          float size) {
  
  upper(tName);
  std::string insertcmd = 
    "INSERT INTO " + tName + " (NAME,STOCK,PRICE,SIZE) " \
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

// user
void SQL::insertIntoTable(std::string tName, 
                          std::string uName, 
                          std::string pass,
                          int admin) {
  upper(tName);
   std::string insertcmd = 
    "INSERT INTO " + tName + " (NAME,PASS,ADMIN) " \
    "VALUES (" 
    + "'" + uName + "'" + ", " 
    + "'" + pass + "'" + ", " 
    + std::to_string(admin) + ");"; \
  sql = insertcmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg << "\n";
    sqlite3_free(errMsg);
  } else {
    std::cout << "Insert into user done successfully\n";
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
    + "where NAME=" + "'" + name + "'; "; \
  sql = updatecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(!sqlite3_changes(db)) {
    std::cout << "Record not found. Please try again." << std::endl;
    throw 000;
  } else {
    std::cout << "Update done successfully\n";
  }
}

void SQL::deleteFromTable(std::string tName, std::string name) {
  upper(tName);
  std::string deletecmd = 
    "DELETE FROM " + tName + " WHERE NAME = '" + name + "';"; \
  sql = deletecmd;
  rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &errMsg);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg;
    sqlite3_free(errMsg);
    throw 001;
  } else {
    std::cout << "Operation done successfully\n";
  }
}

void SQL::checkTable(std::string tName) {
  upper(tName);
  std::string query = "SELECT * FROM " + tName;
  rc = sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
  if(rc != SQLITE_OK) {
    std::cout << "SQL error:\n" << errMsg;
    sqlite3_free(errMsg);
    throw 002;
  } else {
    std::cout << "Operation done successfully\n";
  }
}

void SQL::closeDataBase() {
  sqlite3_close(db);
}

void SQL::populateAlcVector(std::vector<Alcohol> &results) {
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, "SELECT name, price, stock FROM alcohols",
                          -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    std::cout << "SELECT failed: " << sqlite3_errmsg(db) << std::endl;
    throw 000;
  }
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    int price = sqlite3_column_int(stmt, 1);
    int stock = sqlite3_column_int(stmt, 2);
    results.push_back(Alcohol(name, price, stock));
  }
  if (rc != SQLITE_DONE) {
    std::cout << "SELECT failed: " << sqlite3_errmsg(db) << std::endl;
    throw 000;
  }
}

void SQL::findEntryInTable(std::string tName, std::string eName) {
  upper(tName);
  try {
    std::string query = "SELECT * FROM ALCOHOLS WHERE NAME = " 
      + eName + "'; "; \
    sql = query;
    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc != SQLITE_OK) {
      throw 002;
    } else {
      std::cout << "Operation done successfully\n";
    }
  }
  catch(int error) {
    std::cout << "Couldn't find product in 'Alcohols'" << std::endl;
  }

 try {
    std::string query = "SELECT * FROM CHIPS WHERE NAME = " 
      + eName + "'; "; \
    sql = query;
    rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
    if(rc != SQLITE_OK) {
      throw 002;
    } else {
      std::cout << "Operation done successfully\n";
    }
  }
  catch(int error) {
    std::cout << "Couldn't find product in 'Chips'" << std::endl;
  }
}
