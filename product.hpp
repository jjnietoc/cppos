// product.hpp -- pure abstract class for inherititng stock products

#include <string>
#include <cstdint>

#ifndef STOCK_HPP
#define STOCK_HPP

class Product 
{
  private:
    std::string productName;
    std::string productCode;
    uint16_t stock;
    uint8_t price;

  public:
    Product() { }
    Product(const std::string & pn = "Null",
            const std::string & pc = "Null",
            uint16_t s = 0,
            uint8_t p = 0);
    virtual ~Product() = 0;


  };



#endif
