// main app for stock intake and modification
#include "stock.hpp"

#include <vector>
#include <cctype>


void stockLoop() { 
  SQL database;

  database.openDB();
  
  std::string alcTableName = "Alcohols";
  std::string chiTableName = "Chips";
  
  database.createTable(alcTableName, 1);
  database.createTable(chiTableName, 2);

  std::vector<Alcohol> alcohols;
  std::vector<Chips> chips;
  
  std::cout << "\n\ncpPOS v.0.1\nSelect from following (press number):\n" <<
    "(1) ADD products.\n(2) MODIFY products\n(3) DELETE products\n(4) CHECK products\n" << std::endl;
  int response;
  std::cin >> response;
  switch(response) {
    case 1: {
      addProduct(database, alcohols, chips);
    break; 
    }
    // update
    case 2: { 
      modifyProduct(database);
    break;
    }
    // delete
    case 3: {
      deleteProduct(database);
    break;
    }
    // check
    case 4: {
      checkProduct(database);
    break;
    }
  }
}

void addProduct(SQL &database, std::vector<Alcohol>alcohols, std::vector<Chips>chips) {
  std::cout << "Would you like to add any alcohol?\n" <<
    "Press (1) for 'yes' and (2) for 'no': " << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 2) {
    std::cout << "Thank you! Bye!\n" << std::endl;
  } else {
    std::string alcoholName;
    Alcohol::volume alcoholVol;
    Alcohol::type alcoholType;
    int tempVol, tempType;
    uint32_t alcoholStock;
    float alcoholPrice, alcoholSize;
    while(ans != 2 && !std::isalpha(ans)) {  
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Alcohol\nName: " << std::endl;
      std::getline(std::cin, alcoholName);
      std::cout << "Volume (1) ml, (2) litre: " << std::endl;          
      std::cin >> tempVol;
      std::cout << "Type (1) spirit, (2) beer, (3) rtd, (4) r wine, (5) w wine, (6) other: " << std::endl;
      std::cin >> tempType;
      std::cout << "Stock: " << std::endl;
      std::cin >> alcoholStock;
      std::cout << "Price: " << std::endl;
      std::cin >> alcoholPrice;
      std::cout << "Size: " << std::endl;
      std::cin >> alcoholSize;

      alcoholVol = static_cast<Alcohol::volume>(tempVol);
      alcoholType = static_cast<Alcohol::type>(tempType);

      Alcohol alc(alcoholName, 
                  alcoholStock,
                  alcoholPrice,
                  alcoholSize,
                  alcoholVol,
                  alcoholType);

      alcohols.push_back(alc);

      std::cout << "Would you like to add another?\n" <<
        "Press (1) for 'yes' and (2) for 'no': ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> ans;
      }
    }
  std::cout << "Thank you.\n\n" << 
    "Would you like to add any chips?\n" << 
    "Press (1) for 'yes' and (2) for 'no': " << std::endl;
  int ans2;
  std::cin >> ans2;
  if(ans2 == 2) {
    std::cout << "Thank you! Bye!\n" << std::endl;
  } else {
    std::string chipsName;
    uint32_t chipsStock;
    float chipsPrice, chipsSize;
    while(ans2 != 2  && !std::isalpha(ans2)) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Chips\nName: " << std::endl;
      std::getline(std::cin, chipsName);
      std::cout << "Stock: " << std::endl;
      std::cin >> chipsStock;
      std::cout << "Price: " << std::endl;
      std::cin >> chipsPrice;
      std::cout << "Size: " << std::endl;
      std::cin >> chipsSize;
  
      Chips chip(chipsName,
                 chipsStock,
                 chipsPrice,
                 chipsSize);
          
      chips.push_back(chip);

      std::cout << "Would you like to add another one?\n" <<
        "Press (1) for 'yes' and (2) for 'no': " << std::endl;
      std::cin.clear();
      std::cin >> ans2;
    }
  }
  if(alcohols.empty()) {
    std::cout << "Bye!" << std::endl;
  } else {
    std::cout << "Would you like to add the following products to the database?:\nAlcohols:\n";
    std::cout << alcohols;
  }
  if(chips.empty()) {
    std::cout << "Bye!" << std::endl;
  } else {
    std::cout << "Chips:\n";
    std::cout << chips;
  }

  for(int i = 0; i < alcohols.size(); i++) {
    database.insertIntoTable("Alcohols", 
                             alcohols[i].getName(), 
                             alcohols[i].typeToStr(alcohols[i].getType()), 
                             alcohols[i].typeToStr(alcohols[i].getType()), 
                             alcohols[i].getStock(), 
                             alcohols[i].getPrice(), 
                             alcohols[i].getSize());
  }
  
  for(int i = 0; i < chips.size(); i++) {
      database.insertIntoTable("Chips", 
                               chips[i].getName(), 
                               chips[i].getStock(), 
                               chips[i].getPrice(), 
                               chips[i].getSize());
  }
}

void modifyProduct(SQL &database) {
  std::string tName, column, newval, name;
  std::cout << "UPDATE products\nFill the following:\nTable Name: " << std::endl;
  std::cin.ignore();
  std::getline(std::cin, tName);
  std::cout << "Column: " << std::endl;
  std::getline(std::cin, column);
  std::cout << "Name of product: " << std::endl;
  std::getline(std::cin, name);
  std::cout << "New value: " << std::endl; 
  std::getline(std::cin, newval);
  std::cout << "You would like to UPDATE:\n" << name << " in " <<
  tName << " table, and column " << column << " with " << newval <<
    "\nPlease confirm with '1'" << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 1) { 
    try {
      database.updateTable(tName, column, newval, name);
    } catch(int error) {
        std::cin.clear();
        modifyProduct(database);
    }
  } else {
      std::cout << "Bye!" << std::endl;
    }
}

void deleteProduct(SQL &database) {
  std::string tName, name;
  std::cout << "DELETE product\nFill the following:\nTable Name: " << std::endl;
  std::cin.ignore();
  std::getline(std::cin, tName);
  std::cout << "Name of product to be deleted: " << std::endl;
  std::getline(std::cin, name);

  std::cout << "You would like to DELETE:\n" << name << " in table: " << tName <<
    "\nConfirm with '1'" << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 1) {
    try {
      database.deleteFromTable(tName, name);
    } catch(int error) {
      std::cin.clear();
      deleteProduct(database);
    }
  } else {
    std::cout << "Bye!" << std::endl;
  }
}

void checkProduct(SQL &database) {
  std::string tName;
  std::cout << "CHECK products\nFill in the following:\nTable Name: " << std::endl;
  std::cin.ignore();
  std::getline(std::cin, tName);
  
  std::cout << "You would like to check the products in table " + tName <<
    "\nConfirm with '1'" << std::endl;
  int ans;
  std::cin >> ans;
  if(ans == 1) {
    try {
      database.checkTable(tName);
    } catch(int error) {
      std::cin.clear();
      checkProduct(database);
    }
  } else {
    std::cout << "Bye!" << std::endl;
  }
}
