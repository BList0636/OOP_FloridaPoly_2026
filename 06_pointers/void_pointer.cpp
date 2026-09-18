#include <iostream>

int main(){
    //Casting
    //static_cast<type>(expression);

    int num = 21;
    double pi = 3.1415;

    void* ptr = nullptr;

    ptr = &num;
    std::cout << "Int value " << *static_cast<int*>(ptr) << std::endl;

    ptr = &pi;
    std::cout << "Double value " << *static_cast<double*>(ptr) << std::endl;
}