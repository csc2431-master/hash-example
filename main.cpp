#include "product.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;
using std::setw;

int main() {
    unordered_map<string, Product*> map;

    map["FFGARQ"] = new Product("FFGARQ","CFG4", 19.99, "Flux Capacitor");
    map["GHJKK1"] = new Product("GHJKK1","CFG4", 19.99, "Flux Capacitor");
    map["BCC44F"] = new Product("BCC44F","CFG4", 19.99, "Flux Capacitor");
    map["KLSEW1"] = new Product("KLSEW1","CFG4", 19.99, "Flux Capacitor");
    map["PETR77"] = new Product("PETR77","CFG4", 19.99, "Flux Capacitor");

    cout << "Output the elements of the Hash Table" << endl;
    for (auto& p : map){
        cout << p.first << "\t" << p.second->ToString() << endl;
    }
    cout << endl;
    cout << "Output the elements of the Hash Table" << endl;
    for (auto it = map.begin(); it != map.end(); ++it){
        cout << it->first << "\t" << it->second->ToString() << endl;
    }
    cout << endl;
    cout << "Output the buckets of the Hash Table" << endl;
    for (size_t i = 0; i < map.bucket_count(); i++){
        cout << "Bucket #" << setw(2) << i << " contains: " << endl;
        for (auto localIt = map.begin(i); localIt != map.end(i); ++localIt){
            cout << "\t" << localIt->first << " : " << localIt->second->ToString() << endl;
        }
        cout << endl;
    }

    for (auto& p : map){
        delete p.second;
    }

    return 0;
}
