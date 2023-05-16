//
// Created by Carlos R. Arias on 5/16/23.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

class Product {
private:
    char _id[7]; // Always 6 characters
    char _category[5]; // Always 4 characters
    double _price;
    char _description[100]; // Up to 99 characters
public:
    Product(const char* id, const char* category, double price, const char* description);
    Product(const Product& product);
    string ToString()const;
    const char *GetId() const;
    const char *GetCategory() const;
    double GetPrice() const;
    const char *GetDescription() const;
    void SetPrice(double price);
    int Read(istream& input);
    void Write(ostream& output);
};


#endif //HASH_EXAMPLE_PRODUCT_H
