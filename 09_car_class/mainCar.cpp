// Testing file
#include "Car.hpp"
#include "CarDealer.hpp"
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
    Car ferrari_gt("Ferrari", "Super GT", 2020, 13.3);

    CarDealer ferrari_lakeland;
    ferrari_lakeland.addCar(my_car);
    ferrari_lakeland.addCar(ferrari_spider);
    ferrari_lakeland.addCar(ferrari_gt);

    ferrari_lakeland.showInventory();
    return 0;
}