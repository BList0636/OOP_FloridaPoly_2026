#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

class Student{
public:
    Student(const std::string& n, double st_gpa);
    //Destructor
    ~Student();

    bool canGraduate() const;
    void printStudentInfo() const; //name: {} | GPA: {} | {can grad}

    static double getRequiredGPA();
    static void setRequiredGPA(double new_gpa);

    static int getTotalStudents();
private:
    std::string name;
    std::string id;
    double gpa;

    static double required_gpa;
    static int total_students;
    static int next_id;
};

#endif