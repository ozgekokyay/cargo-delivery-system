//
// Created by ozge kokyay on 11.12.2020.
//
#ifndef YENIDEN_FILEREADER_H
#define YENIDEN_FILEREADER_H
#include <string>
#include "DeliverySystem.h"
using namespace std;
class FileReader {
public:

    // delivery system created for the given txt files
    DeliverySystem d;

    // constructor that takes the files names as parameter
    FileReader(string dests, string missions, string trucks, string packages);

    // read txt files and with the given information build the delivery system
    void readDest(string dests);
    void readMissions(string missions);
    void readTruck(string trucks);
    void readPackages(string packages);
    void output();
};


#endif //YENIDEN_FILEREADER_H
