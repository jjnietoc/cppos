// product.hpp -- pure abstract class for inherititng stock products

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <cstdint>


class Product 
{
  private:
    std::string productName, productCode;
    uint16_t stock;
    uint8_t price;

  public:
    Product() { }
    Product(const std::string & pn = "Null",
            const std::string & pc = "Null",
            uint16_t s = 0,
            uint8_t p = 0);
    virtual ~Product() = 0;

    void setName();
    void setProductCode();
    void setStock();
    void setPrice();

    const std::string & getName() { return productName; }
    const std::string & getCode() { return productCode; }
    const uint16_t & getStock() { return stock; }
    const uint8_t & getPrice() { return price; }
  };



#endif
