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
        {"Alice", 101, 3.5},
        {"Bob", 102, 3.6},
        {"Charlie", 103, 3.9},
        {"David", 104, 2.8},
        {"Eva", 105, 3.7}
    };

    Student topStudent = findHighestGPA(roster, 5);
    std::cout << "Siswa dengan GPA tertinggi adalah: " 
              << topStudent.name << " dengan nilai " << topStudent.gpa << std::endl;

    return 0;
}