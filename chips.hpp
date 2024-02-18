// chips.hpp -- derived from product.hpp

#ifndef CHIPS_HPP
#define CHIPS_HPP

#include "product.hpp"

class Chips : public Product
{
  public:
    enum class mass {
      grams = 0    
    };
    
    Chips() { };
    Chips(const std::string & pn = "Null",
          const std::string & pc = "Null",
          uint32_t st = 0,
          uint32_t pr = 0,
          float s = 0.0);
    ~Chips();

    void setSize(float s);
    
    const float getSize() const { return size; }
    
    friend std::ostream& operator<<(std::ostream& out, const std::vector<Chips>&ch);

  private:
    float size;
    mass m;
};

#endif
