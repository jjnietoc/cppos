// header file for stock 
#ifndef STOCK_HPP
#define STOCK_HPP

#include "alcohol.hpp"
#include "chips.hpp"
#include "db.hpp"

void stockLoop();

void addProduct(SQL &database, std::vector<Alcohol>alcohols, std::vector<Chips>chips);
void modifyProduct(SQL &database);
void deleteProduct(SQL &database);
void checkProduct(SQL &database);

#endif
