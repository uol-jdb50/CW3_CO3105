#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using std::vector;
class Student {
public:
    Student() {

    }
    Student(string name, int op1, int op2, int op3, int op4) {
        this->name = name;
        this->op1 = op1;
        this->op2 = op2;
        this->op3 = op3;
        this->op4 = op4;
    }
    string getName() {
        return name;
    }
    int getOption(int preferenceNum) {
        switch (preferenceNum) {
            case 1:
                return op1;
                break;
            case 2:
                return op2;
                break;
            case 3:
                return op3;
                break;
            case 4:
                return op4;
                break;
        }
    }
    static vector<Student> readStudents(char* file) {
        ifstream inFile;
        string name;
        int op1;
        int op2;
        int op3;
        int op4;
        int count = 1;
        std::vector<Student> students;
        const char DELIMITER = ' ';
        inFile.open(file);
        if (!inFile) {
            cout << "Unable to open Student file.";
            exit(1);
        }
        while (inFile) {
            students.resize(count);
            inFile >> name >> op1 >> op2 >> op3 >> op4;
            //std::cout << name << std::endl;
            students.push_back(Student(name, op1, op2, op3, op4));
            count++;
        }
        return students;
    }
private:
    string name;
    int op1;
    int op2;
    int op3;
    int op4;
};
#endif