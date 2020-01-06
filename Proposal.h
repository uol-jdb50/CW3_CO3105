#ifndef PROPOSAL_H
#define PROPOSAL_H
#include <string>
#include <vector>
#include <fstream>
#include "Staff.h"
using namespace std;
using std::vector;
class Proposal {
public:
    Proposal() {
    }
    Proposal(int id, int maxStudents, string name, string supervisor) {
        this->id = id;
        this->maxStudents = maxStudents;
        this->name = name;
    }
    int getId() {
        return id;
    }
    int getMaxStudents() {
        return maxStudents;
    }
    string getName() {
        return name;
    }
    string getSupervisor() {
        return supervisor;
    }
    static vector<Proposal> readProjects(char* file) {
        ifstream inFile;

        int id;
        string staffName = "";
        int maxStudents;
        string proposalName = "";

        std::vector<Proposal> proposals;
        const char DELIMITER = ' ';
        inFile.open(file);
        if (!inFile) {
            cout << "Unable to open Project file.";
            exit(1);
        }
        while (inFile) {
            inFile >> id >> staffName >> maxStudents >> proposalName;
            //std::cout << id << " " << staffName << " " << maxStudents << " " << proposalName << std::endl;
            proposals.push_back(Proposal(id, maxStudents, proposalName, staffName));
        }
        return proposals;
    }

private:
    int id;
    int maxStudents;
    string name;
    string supervisor;
    vector<Student> students;
};
#endif