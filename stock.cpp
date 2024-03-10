// main app for stock intake and modification
#include "alcohol.hpp"
#include "chips.hpp"
#include "db.hpp"

int main(void) {
  // for alcohol
  std::string alcoholName, alcoholCode;
  Alcohol::volume alcoholVol;
  Alcohol::type alcoholType;
  int tempVol, tempType;
  uint32_t alcoholStock;
  float alcoholPrice, alcoholSize;

  // for chips
  std::string chipsName, chipsCode;
  uint32_t chipsStock;
  float chipsPrice, chipsSize;

  // TODO input for alcohol

  // cast for constructor
  alcoholVol = static_cast<Alcohol::volume>(tempVol);
  alcoholType = static_cast<Alcohol::type>(tempType);

  Alcohol alc(alcoholName, 
              alcoholCode, 
              alcoholStock,
              alcoholPrice,
              alcoholSize,
              alcoholVol,
              alcoholType);

  // TODO input for chips

  Chips chip(chipsName,
             chipsCode,
             chipsStock,
             chipsPrice,
             chipsSize);

  SQL database;
  
  std::string tableName;

  // TODO input for db

  database.createTable(tableName);

  // TODO insert for Table for loop
  //
  // TODO update for table for loop
  //
  // TODO for table for loop
  //

}
