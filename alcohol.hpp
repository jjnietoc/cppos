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
    Alcohol(const std::string & pn = "Null",
            const std::string & pc = "Null",
            uint16_t st = 0,
            uint8_t pr = 0,
            float s = 0.0,
            volume v = volume::ml,
            type t = type::other);
  
    ~Alcohol();

    void setSize(float s);
    void setVolume(volume v);
    void setType(type t);
    
    const float getSize() { return size; }
    const type getType() { return ty; }
    const volume getVolume() { return vol; }

    friend std::ostream& operator<<(std::ostream& out, const std::vector<Alcohol>& a);

  private: 
    float size;
    volume vol;
    type ty;

  };


#endif

