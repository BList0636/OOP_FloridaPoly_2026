#include <iostream>
#include <string>
struct Lecture{
    std::string title;
    int duration;
};


int main(){
    int a;
    Lecture oop;

    oop.title = "Classes and Objects";
    oop.duration = 50*60;

    Lecture math {"Graph", 75*60};
}