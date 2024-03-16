// chips.hpp -- derived from product.hpp

#ifndef CHIPS_HPP
#define CHIPS_HPP

#include "product.hpp"

class Chips : public Product
{
  public:
    enum class mass {
      grams    
    };
    
    Chips() { };
    Chips(const std::string & pn = "Null",
          int st = 0,
          float pr = 0,
          float s = 0.0);
    ~Chips();

    void setSize(float s);
    void setProductCode() override;
    
    const float getSize() const { return size; }
    const std::string getIdentifier() const { return "chips"; }

    const char* massToStr(Chips::mass m); 
    
    friend std::ostream& operator<<(std::ostream& out, const std::vector<Chips>&ch);

  private:
    float size;
    mass m;
};

#endif
