#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

class Student{
public:
    Student(const std::string& n, double st_gpa);

    bool canGraduate() const;
    void printStudentInfo() const; //name: {} | GPA: {} | {can grad}
private:
    std::string name;
    double gpa;

    static double required_gpa;
};

#endif