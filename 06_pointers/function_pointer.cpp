#include <iostream>

int add(int a, int b) {return a+b;}
int subtract(int a, int b){return a-b;}

int operate (int a, int b, int (*operation)(int,int)){
    return operation(a,b);
}

int main(){
    //Function pointer
    // return_type (*function_pointer_name)([paramenters])
    std::cout << "Addition: " << operate(10, 17, add) << std::endl;
    std::cout << "Subtraction: " << operate(10, 17, subtract) << std::endl;

    // Lambda
    auto mult = [](int a, int b) {return a*b;};
    std::cout << "Multipication: " << operate(10, 17, mult) << std::endl;

}