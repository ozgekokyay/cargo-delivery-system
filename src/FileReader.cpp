//
// Created by ozge kokyay on 11.12.2020.
//

#include "FileReader.h"
#include "fstream"
#include "DeliverySystem.h"
#include "City.h"
#include <sstream>
#include "vector"

// calls all the reader functions
FileReader::FileReader(string dests, string missions, string trucks, string packages) {
    readDest(dests);
    readPackages(packages);
    readTruck(trucks);
    readMissions(missions);
    output();

}

// read dest file and add cities to delivery system
void FileReader::readDest(string dests) {
    ifstream file;
    file.open(dests);
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            d.addCity(line);
        }
    }
    file.close();
}


// read packages and add packages to given city
void FileReader::readPackages(string packages)  {
    ifstream file;
    file.open(packages);
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Vector of string to save tokens
            vector <string> tokens;
            // stringstream class check1
            stringstream check1(line);
            string intermediate;

            // Tokenizing w.r.t. space ' '
            while(getline(check1, intermediate, ' '))
            {
                tokens.push_back(intermediate);
            }
            d.getCity(tokens[1])->addPackage(tokens[0]);
        }

    }
    file.close();
}


void FileReader::readTruck(string trucks) {
    ifstream file;
    file.open(trucks);
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Vector of string to save tokens
            vector <string> tokens;

            // stringstream class check1
            stringstream check1(line);

            string intermediate;

            // Tokenizing w.r.t. space ' '
            while(getline(check1, intermediate, ' '))
            {
                tokens.push_back(intermediate);
            }
            d.getCity(tokens[1])->addTruck(tokens[0]);

        }

    }
    file.close();
}

void FileReader::readMissions(string missions) {

    ifstream file;
    file.open(missions);
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Vector of string to save tokens
            vector <string> tokens;

            // stringstream class check1
            stringstream check1(line);

            string intermediate;

            // Tokenizing w.r.t. space ' '
            while(getline(check1, intermediate, '-'))
            {
                tokens.push_back(intermediate);
            }
            vector <int> c;
            stringstream check2(tokens[5]);
            string intermediate2;
            int ci;
            while(getline(check2, intermediate2, ','))
            {
                ci = stoi(intermediate2);
                c.push_back(ci);
            }


            int a = stoi(tokens[3]);
            int b = stoi(tokens[4]);

            d.makeTransportation(tokens[0],tokens[1],tokens[2],a,b, c);
        }

    }
    file.close();
}

void FileReader::output() {
    d.print();
}
