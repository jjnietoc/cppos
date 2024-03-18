// alcohol.hpp -- derived from product.hpp

#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "product.hpp"

class Alcohol : public Product 
{
  public:
    enum class volume {    // this or just input in ml and create
      // function to convert
      ml = 1,
      l = 2
    };
     enum class type {
      spirit = 1,
      beer = 2,
      rtd = 3,
      red_wine = 4,
      white_wine = 5,
      other = 6
    };

    Alcohol() { };
    Alcohol(const std::string & pn = "Null",
            int st = 0,
            float pr = 0,
            float s = 0.0,
            volume v = volume::ml,
            type t = type::other);
  
    ~Alcohol();

    void setSize(float s);
    void setVolume(volume v);
    void setType(type t);
    void setProductCode() override;
    
    const float getSize() const { return size; }
    const type getType() const { return ty; }
    const volume getVolume() const { return vol; }
    const std::string getIdentifier() const { return "alcohol"; }

    const char* volToStr(Alcohol::volume v);
    const char* typeToStr(Alcohol::type t);

    friend std::ostream& operator<<(std::ostream& out, const std::vector<Alcohol>& a);

  private: 
    float size;
    volume vol;
    type ty;

  };


#endif

