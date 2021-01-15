//
// Created by ozge kokyay on 11.12.2020.
//

#ifndef YENIDEN_DELIVERYSYSTEM_H
#define YENIDEN_DELIVERYSYSTEM_H
#include "City.h"
#include <string>
#include <vector>
#include "fstream"
extern ofstream output;

class DeliverySystem {
public:

//    default constructor
    DeliverySystem();
// city vector that holds pointer to cities in delivery system
    vector<City*> city;

// add new city to delivery system
    void addCity(string name);

//    return the pointer of the city given name
    City* getCity(string name);

//    print all packages and trucks that city has
    void print();

//    make the transportation choose a truck and carry packages the given cities
    void makeTransportation(const string& A, const string& B, const string& C, int a, int b, vector<int> c);
};


#endif //YENIDEN_DELIVERYSYSTEM_H
