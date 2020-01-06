#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Proposal.h"
#include "Staff.h"
#include "Allocation.h"

using namespace std;
int main(int argc, char* argv[]) {
    vector<Staff> staff;
    vector<Proposal> proposals;
    vector<Student> students;
    for (int i = 0; i < argc; i++) {
        switch (i) {
            case 1:
                staff = Staff::readStaff(argv[1]);
                break;
            case 2:
                proposals = Proposal::readProjects(argv[2]);
                break;
            case 3:
                students = Student::readStudents(argv[3]);
                break;
        }
    }
    return 0;
}