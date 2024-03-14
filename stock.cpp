// main app for stock intake and modification
#include "alcohol.hpp"
#include "chips.hpp"
#include "db.hpp"

#include <vector>

void alcInput(Alcohol &alc);

int main(void) {
  // TODO create 2 tables, one for alcohol and one for chips, or better yet
  // think of structure for different tables in db
  //SQL database;
  
  //std::string tableName;

  //database.createTable(tableName);

  std::vector<Alcohol> alcohols;
  std::vector<Chips> chips;

  std::cout << "cpPOS v.0.0\nWould you like to add any alcohol?\n" <<
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
    while(std::cin >> ans) {  
      if(ans == 1) {
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
      } else {
        break;     
      }
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
      while(std::cin >> ans2) {
        if(ans2 == 1) {
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
        } else {
          break;
        }
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
}
