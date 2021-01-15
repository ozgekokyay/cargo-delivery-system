#include <fstream>
#include "FileReader.h"
#include "string"

using namespace std;
ofstream output;
int main(int args, char** argv) {
    string dests = argv[1];
    string packages = argv[2];
    string trucks = argv[3];
    string missions = argv[4];
    string result = argv[5];

    output.open(result);

    FileReader fileReader(dests,missions,trucks,packages);
}
