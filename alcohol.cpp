// alcohol.cpp -- implementation of alcohol methods

#include "alcohol.hpp"
#include <iostream>

// NOTE need to override virtual function methods

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

Alcohol::~Alcohol() {}

void Alcohol::setSize(float s) {
  if(size < 0.0)
    std::cout << "size needs to be larger than 0.0" << std::endl;
  else 
    size = s;
}

void Alcohol::setVolume(volume v) {
  if(v != Alcohol::volume::l || v != Alcohol::volume::ml)
    std::cout << "Please select either ml or l";
  else {
    vol = v;
  }
}

void Alcohol::setType(type t) {
  if(t != Alcohol::type::spirit || t != Alcohol::type::beer || t != Alcohol::type::rtd || t != Alcohol::type::red_wine || 
    t != Alcohol::type::white_wine || t != Alcohol::type::other) {
    std::cout << "Please select from the following:\n"
      << "spirit\nbeer\nrtd\nred_wine\nwhite_wine\nother"
      <<std::endl;
  } else {
    ty = t;
  }
}

void setName(std::string pn) override {
  productName = pn;
}




