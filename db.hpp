#ifndef DB_HPP
#define DB_HPP

#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <typeindex>
#include "alcohol.hpp"

class SQL
{
  private:
    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    std::string sql;
    //char *sql;
    const char* data = "Callback function called";

  public:
    SQL();
    ~SQL();
    int openDB();
    void createTable(std::string tName, int type);
    void insertIntoTable(std::string tName,
                           std::string name, 
                           std::string type, 
                           std::string volume,
                           int stock,
                           float price,
                           float size);
    void insertIntoTable(std::string tName,
                         std::string name,
                         int stock,
                         float price,
                         float size);
    void insertIntoTable(std::string tName,
                         std::string uName, 
                         std::string pass,
                         int admin);
    void updateTable(std::string tName,
                     std::string column, 
                     std::string newval,
                     std::string name);
    void deleteFromTable(std::string tName, std::string name);
    void checkTable(std::string tName);
    void closeDataBase();

    std::string upper(std::string name);    // for easier name transformations
    const char* typeToSQL(std::type_index ti);

    std::vector<Alcohol> populateAlcVector();

    static int callback(void *data, int argc, char **argv, char **azColName) {
      int i;
      for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      }
      std::cout << "\n";
      return 0;
    };
  };  

#endif
