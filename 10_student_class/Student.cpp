#include "Student.hpp"
#include <string>
#include <iostream>

double Student::required_gpa = 2.5;

Student::Student(const std::string& n, double st_gpa) : name(n), gpa(st_gpa) {}

bool Student::canGraduate() const {
    return gpa >= required_gpa;
}

void Student::printStudentInfo() const {
    std::cout << "Name: " << name << " | GPA: " << gpa;
    std::cout << " | Can graduate: " << (canGraduate() ? "YES" : "NO") << std::endl;
}