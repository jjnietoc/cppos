// chips.cpp -- compile with chips.hpp

#include "chips.hpp"

#include <iostream>
#include <vector>
#include <map>

Chips::Chips(const std::string & pn,
             uint32_t st,
             float pr,
             float s) : Product(pn, st, pr) {
  setSize(s);
  setProductCode();
  m = mass::grams;
}

void Chips::setProductCode() {
  int temp = rand() % 90000 + 10000;
  productCode = std::to_string(temp);
};

void Chips::setSize(float s) {
  if(size < 0.0)
    std::cout << "Size needs to be larger than 0.0" << std::endl;
  else
    size = s;
}

std::ostream& operator<<(std::ostream& out, const std::vector<Chips>&ch) {
  out << "List of chips:\n";
  size_t last = ch.size() - 1;
  for(size_t i = 0; i < ch.size(); ++i) {
    out << i + 1 << ") " << ch[i].getName() << ". ID: "
      <<ch[i].getCode() << ".\n";
    if(i != last)
      out << "\n";
  }
  out << "\n";
  return out;
}

const char* Chips::massToStr(Chips::mass m) {
  const std::map<Chips::mass, const char*> myEnumStrings {
  { Chips::mass::grams, "grams" }
  };
  auto it = myEnumStrings.find(m);
  return it == myEnumStrings.end() ? "Out of bounds" : it->second;
}
