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
    Product(const std::string & pn,
            const std::string & pc,
            uint16_t s,
            uint8_t p);
    virtual ~Product() = 0;

    void setName(std::string pn);
    void setProductCode(std::string pc);
    void setStock(uint16_t stock);
    void setPrice(uint8_t price);

    const std::string & getName() { return productName; }
    const std::string & getCode() { return productCode; }
    const uint16_t & getStock() { return stock; }
    const uint8_t & getPrice() { return price; }
  };



#endif
