// product.hpp -- pure abstract class for inherititng stock products

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <cstdint>


class Product 
{
  protected:
    std::string productName, productCode;
    int stock;
    float price;

  public:
    Product() { }
    Product(const std::string & pn,
            int st,
            float p) 
    { setName(pn); setProductCode(); setStock(st); setPrice(p); };
    virtual ~Product() {};

    void setName(const std::string & pn) { productName = pn; }; 
    virtual void setProductCode() { productCode = "NULL"; };
    void setStock(int st) { stock = st; };
    void setPrice(float pr) { price = pr; };

    const std::string & getName() const { return productName; }
    const std::string & getCode() const { return productCode; }
    const int & getStock() const { return stock; }
    const float & getPrice() const { return price; }
  };



#endif
