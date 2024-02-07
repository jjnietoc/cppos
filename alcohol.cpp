// alcohol.cpp -- implementation of alcohol methods

#include "alcohol.hpp"
#include <ostream>

Alcohol::Alcohol(const std::string & pn,
            const std::string & pc,
            uint16_t st,
            uint8_t pr,
            float s,
            volume v,
            type t) {
  setName(pn);
  setProductCode(pc);
  setStock(st);
  setPrice(pr);
  setSize(s);
  setVolume(v);
  setType(t);
}

void Alcohol::setSize(float s) {
  if(size < 0.0)
    std::cout << "size needs to be larger than 0.0";
  else 
    size = s;
}



