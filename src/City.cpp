//
// Created by ozge kokyay on 11.12.2020.
//
#include <string>
#include "City.h"

using namespace std;
City::City(string name) {
    this->name = name;

}

string City::getName() {
    return name;
}

// addPackage function add package to the package stack
void City::addPackage(string package) {
    p.push(package);

}
// getPackage function call the print function of the package stack
void City::getPackage() {
    p.print();
}

//addTruck function enqueue a new truck to this citys truck queue
void City::addTruck(string truck) {
    t.enqueue(truck);

}

// getTruck function call the print function and print out all trucks
void City::getTruck() {
    t.print();
}


//chooseTruck function choose the first member of the truck queue and return the truck
string City::chooseTruck() {
    string peek = t.peek();
    t.dequeue();
    return peek;


}

//carryPackage function carry the package on the top of stack and return the package
string City::carryPackage() {
    string pack = p.top();
    p.pop();
    return pack;
}



