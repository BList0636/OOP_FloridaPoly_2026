#include <iostream>
#include <string>
#include <iomanip>

class Route {
public:
    Route(const std::string& source, const std::string& destination, int length){
        (*this).source = source;
        (*this).destination = destination;
        (*this).length = length;
    }

    void print(){
        std::cout  << "{" << source << " -> " << destination << ", " << length << " miles}\n";
    }

    void setDestination(const std::string& dest){
        destination = dest;
    }

private:
    std::string source;
    std::string destination;
    int length;
};


int main(){
    /*Before constructor:
    Route trip;

    trip.source = "Lakeland";
    trip.destination = "Orlando";
    trip.length = 45;

    trip.print();

    Route summer_trip;
    summer_trip.source = "Lakeland";
    summer_trip.destination = "Paris";

    summer_trip.print();
    */

    Route trip("Lakeland", "Orlando", 45);
    trip.print();

    Route summer_trip("Lakeland", "Paris", 6000);
    summer_trip.print();
}