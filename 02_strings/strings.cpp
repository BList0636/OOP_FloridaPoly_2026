#include <iostream>
#include <string>
using std::string;

int main(){
    string name;
    string animal;

    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Enter your favorite animal: ";
    getline(std::cin, animal);

    string introduction = "Agent " + name;
    introduction += ", also known as the " + animal + ".";

    std::cout << introduction << std::endl;
    std::cout << "Your identity contains " << introduction.length() << " characters.";
}

