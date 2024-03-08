#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <iostream>

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
    void createTable(std::string name);
    void insertIntoTable(std::string tName,
                         std::string name, 
                         std::string type, 
                         std::string volume,
                         int price,
                         int stock,
                         float size);
    void updateTable(std::string tName,
                     std::string column, 
                     std::string newval,
                     std::string name);
    void deleteFromTable(std::string tName, std::string name);
    std::string upper(std::string name);    // for easier name transformations
  };
