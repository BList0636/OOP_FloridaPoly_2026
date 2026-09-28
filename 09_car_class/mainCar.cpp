// Testing file
#include "Car.hpp"
#include <iostream>

int main(void) {
    // Create a Car object
    Car my_car;
    my_car.printInfo();
    
    my_car.setMake("Ferrari");
    my_car.setModel("F50");
    my_car.setYear(2015);
    my_car.setMPG(14.2);

    std::cout << std::endl;
    my_car.printInfo();

    Car ferrari_spider("Ferrari", "Spider", 2021, 17.2);

    return 0;
}