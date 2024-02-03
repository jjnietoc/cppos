// alcohol.hpp -- derived from product.hpp

#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "product.hpp"

class Alcohol : public Product 
{
  public:
    enum class volume {    // this or just input in ml and create
      // function to convert
      ml,
      l
    };
     enum class type {
      spirit,
      beer,
      rtd,
      red_wine,
      white_wine,
      other
    };

    Alcohol();
    Alcohol(const std::string & pn,
            const std::string & pc,
            uint16_t st,
            uint8_t pr,
            float s,
            volume v,
            type t);
  
    ~Alcohol();

    void setSize();
    void setVolume();
    void setType();
    
    const float getSize() { return size; }
    const type getType() { return ty; }
    const volume getVolume() { return vol; }


  private: 
    float size;
    volume vol;
    type ty;

  };


#endif

