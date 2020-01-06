#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <vector>
#include <fstream>
#include "Proposal.h"
using std::vector;
using namespace std;
class Staff {
public:
    Staff() {

    }
    Staff(string name, int load) {
        this->name = name;
        this->load = load;
    }
    string getName() {
        return name;
    }
    int getLoad() {
        return load;
    }
    static vector<Staff> readStaff(char* file) {
        ifstream inFile(file);
        string name = "";
        int load;
        int count = 1;
        std::vector<Staff> staff;
        const char DELIMITER = ' ';
        if (!inFile) {
            cout << "Unable to open Staff file.";
            exit(1);
        }
        while (inFile) {
            staff.resize(count);
            getline(inFile, name, DELIMITER);
            inFile >> load;
            staff.push_back(Staff(name, load));
            count++;
        }
        return staff;
    }

private:
    string name;
    int load;
    //std::vector<Proposal> projects;
};
#endif