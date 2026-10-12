#include <iostream>
#include <string>

class Hello {
public:
    Hello(){
        std::cout << "No arg constructor for " << this << std::endl;
    }

    Hello(int size){
        (*this).size = size;
        std::cout << "One arg constructor for " << this << std::endl;
        (*this).messages = new std::string[size];
    }

    ~Hello(){
        std::cout << "Destructor for " << this << std::endl;
    }

    void bye() const{
        std::cout << "Bye!!!\n\n";
    }

private:
    int size;
    std::string* messages;

};

int main(){
    Hello* hi = new Hello;

    std::cout << hi << std::endl;

    hi->bye();

    delete hi;

}