#include <iostream>
#include <string>
#include <iomanip>

class Route {
public:
    Route(const std::string& source, const std::string& destination, int length, std::string travel_type = "Car"){
        (*this).source = source;
        (*this).destination = destination;
        (*this).length = length;
        (*this).travel_type = travel_type;
    }

    const void print(){
        std::cout  << "{" << source << " -> " << destination << ", " << length << " miles}\n";
    }

    void setDestination(const std::string& dest){
        destination = dest;
        updateLength();
    }
    
    void setSource(const std::string& sour){
        source = sour;
        updateLength();
    }
    
    const std::string getSource(){
        return source;
    }

    const std::string getDestination(){
        return destination;
    }

    const int getLength(){
        return length;
    }

private:
    void updateLength(){
        length = -1;
    }

    std::string source;
    std::string destination;
    std::string travel_type;
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
    summer_trip.setDestination("Rome");
    summer_trip.print();
}