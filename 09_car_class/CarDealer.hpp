#ifndef CARDEALER_HPP

#define CARDEALER_HPP
#include "Car.hpp"
#include <iostream>
#include <vector>
#include <string>

class CarDealer{
public:
    void addCar(const Car& car);
    void showInventory() const;
private:
    std::vector<Car> inventory;
};

#endif