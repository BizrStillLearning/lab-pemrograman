#include <iostream>
#include <string>

struct Student {
    std::string name;
    int id;
    double gpa;
};

Student findHighestGPA(Student arr[], int size) {
    Student highest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i].gpa > highest.gpa) {
            highest = arr[i];
        }
    }
    return highest;
}

int main() {
    Student roster[5] = {
        {"Abidzar", 1, 3.5},
        {"Beni", 2, 3.6},
        {"Kaizer", 3, 3.9},
        {"Fathul", 4, 2.8},
        {"Esan", 5, 3.7}
    };

    Student topStudent = findHighestGPA(roster, 5);
    std::cout << "Siswa dengan IPK tertinggi adalah: "
              << topStudent.name << " dengan nilai " << topStudent.gpa << std::endl;

    return 0;
}