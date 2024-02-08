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
  Product(pn, pc, st, pr);
  setSize(s);
  setVolume(v);
  setType(t);
}

void Alcohol::setSize(float s) {
  if(size < 0.0)
    std::cout << "size needs to be larger than 0.0" << std::endl;
  else 
    size = s;
}

void Alcohol::setVolume(volume v) {
  if(v > 2)
    std::cout << "Please select either ml or l";
  else {
    volume = v;
  }
}

void Alcohol::setType(type t) {
  if(type > 6)
    std::cout << "Please select from the following:\n"
      << "spirit\nbeer\nrtd\nred_wine\nwhite_wine\nother"
      <<std::endl;
  else {
    type = t;
  }
}




