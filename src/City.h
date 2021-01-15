//
// Created by ozge kokyay on 11.12.2020.
//

#ifndef YENIDEN_CITY_H
#define YENIDEN_CITY_H
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

class City {
private:
    string name;


private:
    // p includes all packages that city has
    Stack<string> p;
    // t include all trucks that city has
    Queue<string> t;


public:
    //default constructor
    City(string name="");
    string getName();

//     functions for package stack
    void addPackage(string package);
    void getPackage();
    string carryPackage();

//    functions for truck queue
    void addTruck(string truck);
    void getTruck();
    string chooseTruck();
};


#endif //YENIDEN_CITY_H
