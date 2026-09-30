#include <iostream>
#include <string>
#include "Car.hpp"

Car::Car() {
    make = "-";
    model = "-";
    year = -1;
    mpg = -1;
}

Car::Car(std::string _make, std::string _model, int _year, double _mpg){
    make = _make;
    model = _model;
    year = _year;
    mpg = _mpg;
}

void Car::printInfo() const {
    std::cout << "Make\t\t" << make << std::endl;
    std::cout << "Model\t\t" << model << std::endl;
    std::cout << "Year\t\t" << year << std::endl;
    std::cout << "MPG\t\t" << mpg << std::endl;
}


// Implement getters and setters
const std::string Car::getMake(){
    return make;
}

const std::string Car::getModel(){
    return model;
}

const int Car::getYear() {
    return year;
}

const double Car::getMPG() {
    return mpg;
}

void Car::setMake(const std::string& mk){
    make = mk;
}

void Car::setModel(const std::string& md){
    model = md;
}

void Car::setYear(int y){
    year = (y > 1900 && y < 2027) ? y : -1;
}

void Car::setMPG(double new_mpg){
    mpg = (new_mpg > 0) ? new_mpg : -1;
}