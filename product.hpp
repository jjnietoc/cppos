// product.hpp -- pure abstract class for inherititng stock products

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <cstdint>


class Product 
{
  protected:
    std::string productName, productCode;
    uint16_t stock;
    float price;

  public:
    Product() { }
    Product(const std::string & pn,
            const std::string & pc,
            uint16_t s,
            float p) 
    { setName(pn); setProductCode(pc); setStock(s); setPrice(p); };
    virtual ~Product() {};

    void setName(const std::string & pn) { productName = pn; }; 
    void setProductCode(const std::string & pc) { productCode = pc; };
    void setStock(uint16_t st) { stock = st; };
    void setPrice(float pr) { price = pr; };

    const std::string & getName() const { return productName; }
    const std::string & getCode() const { return productCode; }
    const uint16_t & getStock() const { return stock; }
    const float & getPrice() const { return price; }
  };



#endif
