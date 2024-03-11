// alcohol.cpp -- implementation of alcohol methods

#include <iostream>
#include <vector>
#include <map>

#include "alcohol.hpp"

Alcohol::Alcohol(const std::string & pn,
            uint32_t st,
            float pr,
            float s,
            volume v,
            type t) : Product(pn, st, pr) { 
  setSize(s);
  setVolume(v);
  setType(t);
}

Alcohol::~Alcohol() {}

void Alcohol::setProductCode() {
  int temp = rand() % 90000 + 10000;
  productCode = std::to_string(temp);
}

void Alcohol::setSize(float s) {
  if(size < 0.0)
    std::cout << "size needs to be larger than 0.0" << std::endl;
  else 
    size = s;
}

void Alcohol::setVolume(volume v) {
    vol = v;
}

void Alcohol::setType(type t) {
    ty = t;
}

std::ostream& operator<<(std::ostream& out, const std::vector<Alcohol>& a) {
  out << "List of products:\n";
  size_t last = a.size() - 1;
  for(size_t i = 0; i < a.size(); ++i) {
    out << i + 1 << ") " << a[i].getName() << ". ID: "
      << a[i].getCode() << ".\n" << a[i].getSize();
    if(i != last)
      out << "\n";
  }
  out << "\n";
  return out;
}

const char* Alcohol::volToStr(Alcohol::volume v) {
  const std::map<Alcohol::volume, const char*> myEnumStrings {
  { Alcohol::volume::l, "liter" },
  { Alcohol::volume::ml, "mililiter" }  
  };
  auto it = myEnumStrings.find(v);
  return it == myEnumStrings.end() ? "Out of range" : it-> second;
}

const char* Alcohol::typeToStr(Alcohol::type t) {
  const std::map<Alcohol::type, const char*> myEnumStrings {
  { Alcohol::type::spirit, "spirit" },
  { Alcohol::type::beer, "beer" },
  { Alcohol::type::rtd, "rtd" },
  { Alcohol::type::red_wine, "red wine" },
  { Alcohol::type::white_wine, "white wine" },
  { Alcohol::type::other, "other" }
  };
  auto it = myEnumStrings.find(t);
  return it == myEnumStrings.end() ? "Out of range" : it->second;
}
