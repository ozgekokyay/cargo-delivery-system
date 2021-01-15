//
// Created by ozge kokyay on 11.12.2020.
//
#include <fstream>
#include "iostream"
#include "DeliverySystem.h"
#include "algorithm"
using namespace std;

//    default constructor
DeliverySystem::DeliverySystem() {
}

// add new city to delivery system
void DeliverySystem::addCity(string name) {
    City *c= new City(name);
    city.push_back(c);

}

//    return the pointer of the city given name
City *DeliverySystem::getCity(string name) {
    City *cPtr ;
    for(int i=0; i<city.size(); i++) {
        if(city[i]->getName() == name) {
            cPtr = city[i];
            return cPtr;
        }
    }
    return nullptr;
}

// print packages and trucks of all cities in the delivery system
void DeliverySystem::print() {
    for(int i=0; i<city.size(); i++) {

        //name of the city
        output<< city[i]->getName()<<endl;
        output<< "Packages:"<< endl;
        // packages that city has
        city[i]->getPackage();

        output<< "Trucks:" << endl;
        // trucks that city has
        city[i]->getTruck();
        output<< "-------------" << endl;
    }
}

/* transportation start from A to B and end at C
 * a is the number of packages taken from city A
 * b is the number of packages taken from city B
 * vector c includes indexes of the packages taken from city A to leave city B
 */
void DeliverySystem::makeTransportation(const string& A, const string& B, const string& C, int a, int b, vector<int> c) {
    // pointers to city A, B and C
    City *cityPtr = getCity(A);
    City *bPtr = getCity(B);
    City *cPtr = getCity(C);

    // truck from A added to C
    string truck = cityPtr->chooseTruck();
    cPtr->addTruck(truck);

    // packB includes packages from B to carry to C
    vector<string> packB;
    for(int i=0; i < b; i++){
        string pack2 = bPtr->carryPackage();
        packB.push_back(pack2);
    }

    // packages includes packages from A that given indexes of c
    vector<string> packages;
    for(int j=0; j < a; j++) {
        vector<int>::iterator it;
        it = find(c.begin(), c.end(), j);
        // the package that carried
        string pack = cityPtr->carryPackage();

        // in the given indexes so added to packages vector
        if(it != c.end() ){
            packages.push_back(pack);
        }
        // not in given indexes so carried to C
        else{
            cPtr->addPackage(pack);
        }
    }
    // add packages to B with in the order of given indexes
    for(int i=0; i < packages.size(); i++){
        int j= c[i];
        bPtr->addPackage(packages[j]);
    }
    // add packages from city B to city C
    for(int i=0; i < b; i++){
        string pack2 = packB[i];
        cPtr->addPackage(pack2);
    }
}

