#include "Student.hpp"
#include <string>
#include <iostream>

double Student::required_gpa = 2.5;
int Student::total_students = 0;
int Student::next_id = 1000;

Student::Student(const std::string& n, double st_gpa) : name(n), gpa(st_gpa) {
    total_students++;
    id = "U00000" + std::to_string(next_id);
    next_id += 5;
}

Student::~Student(){
    total_students--;
}

bool Student::canGraduate() const {
    return gpa >= required_gpa;
}

void Student::printStudentInfo() const {
    std::cout << "Name: " << name;
    std::cout << " | GPA: " << gpa;
    std::cout << " | Can graduate: " << (canGraduate() ? "YES" : "NO");
    std::cout << " | ID: " << id;
    std::cout << std::endl;
}

double Student::getRequiredGPA() {
    return required_gpa;
}

int Student::getTotalStudents() {
    return total_students;
}

void Student::setRequiredGPA(double new_gpa) {
    required_gpa = (new_gpa >= 2.5 && new_gpa <= 4.0) ? new_gpa : required_gpa;
}
