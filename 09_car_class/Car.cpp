#include <iostream>
#include <string>
#include "Car.hpp"


void Car::printInfo() const {
    std::cout << "Make\t\t" << make << std::endl;
    std::cout << "Model\t\t" << model << std::endl;
    std::cout << "Year\t\t" << year << std::endl;
    std::cout << "MPG\t\t" << mpg << std::endl;
}


// Implement getters and setters