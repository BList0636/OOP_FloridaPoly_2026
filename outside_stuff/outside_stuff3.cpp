#include <algorithm>
#include <iostream>

struct Item{
    Item(double _weight, double _value) : weight(_weight), value(_value) {}

    double weight;
    double value;

    double density() const{
        return value/weight;
    }
};

class Knapsack{
public:
    Knapsack(double capacity) : maxCapacity(capacity), usedCapcity(0), valueInside(0) {}

    double tryAddItem(const Item& item){
        if (item.weight > getRemainingCapacity()){
            double frac = getRemainingCapacity() / item.weight;
            usedCapcity = maxCapacity;
            valueInside = frac* item.value;
            return frac;
        }
        else {
            usedCapcity += item.weight;
            return 1;
        }
    }

    double getRemainingCapacity(){
        return maxCapacity - usedCapcity;
    }
private:
    double valueInside;
    double maxCapacity;
    double usedCapcity;
};

bool densityComparer(const Item& p1, const Item& p2) { 
    return (p1.density() > p2.density()); 
}


int main(){
    const int SIZE = 5;
    //item list
    Item items[SIZE] = {Item(1,1), Item(6,7), Item(2,3), Item(4,6),Item(12,4)};
    Knapsack sack(10);

    //sort list by density
    std::sort(items, items + SIZE, densityComparer);
    double addedAmount[SIZE] = {0};
    //loop until getRemainingCapacity = 0
    for (int i = 0; i < SIZE && sack.getRemainingCapacity() != 0; i++){
        double amount = sack.tryAddItem(items[i]);
        //record how much was added
        addedAmount[i] = amount;

        std::cout << "Item " << i;
        std::cout << " (w:" << items[i].weight << " v:" << items[i].value << " d:" << items[i].density();
        std::cout << ") Added: " << amount << std::endl;


    }
    //build output

    return 0;
}


