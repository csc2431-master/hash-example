//
// Created by Carlos R. Arias on 5/16/23.
//

#include "product.h"

#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
using std::string;
using std::stringstream;
using std::istream;
using std::ostream;

const char *Product::GetId() const {
    return _id;
}

const char *Product::GetCategory() const {
    return _category;
}

double Product::GetPrice() const {
    return _price;
}

const char *Product::GetDescription() const {
    return _description;
}

void Product::SetPrice(double price) {
    _price = price;
}

Product::Product(const char *id, const char *category, double price, const char *description) {
    _price = price;
    strncpy(_id, id, 6);
    _id[6] = '\0';
    strncpy(_category, category, 4);
    _category[5] = '\0';
    strncpy(_description, description, 99);
    _description[99] = '\0';
}

Product::Product(const Product &product) {
    strcpy(_id, product._id);
    strcpy(_category, product._category);
    _price = product._price;
    strcpy(_description, product._description);
}

string Product::ToString() const {
    stringstream ss;
    ss << "{\"id\":\"" << _id << "\", \"category\":\"" << _category << "\", \"price\":" << _price << ", \"description\":\"" << _description << "\"}";
    return ss.str();
}

int Product::Read(istream &input) {
    string temp;
    input >> temp;
    if (input.fail())
        return 0;
    strncpy(_id, temp.c_str(), 6);
    _id[6] = '\0';
    input >> temp;
    if (input.fail())
        return 0;
    strncpy(_category, temp.c_str(), 4);
    _category[5] = '\0';
    input >> _price;
    if (input.fail())
        return 0;
    input >> temp;
    if (input.fail())
        return 0;
    strncpy(_description, temp.c_str(), 99);
    _description[99] = '\0';
    return 1;
}

void Product::Write(ostream &output) {
    output << _id << " " << _category << " " << _price << " " << _description;
}
