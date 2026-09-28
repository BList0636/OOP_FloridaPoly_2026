#include <iostream>

namespace student{
    int id;
}

namespace course{
    int id;
}

int main(){
    std::cout << "Enter Student ID: ";
    std::cin >> student::id;

    std::cout << "Enter Course ID: ";
    std::cin >> course::id;

    std::cout << std::endl << "--- Registration Information ---" << std::endl;
    std::cout << "Student ID: " << student::id << std::endl;
    std::cout << "Course ID: " << course::id << std::endl;


}