#include <iostream>
#include <cmath>

void countdown(int n){
    if (n <= 0){
        std::cout << "Reached base case\n";
        return;
    }
    std::cout << n << " ";
    countdown(n-1);
}

void countup(int n){
    if (n <= 0){
        std::cout << "Reached base case\n";
        return;
    }
    countup(n-1);

    std::cout << n << " ";
}

double power(double base, int exp){
    if (exp > 0){
        return power(base,exp-1)*base;
    }
    else if(exp < 0){
        return power(base,exp+1)/base;
    }
    else{
        return 1;
    }
}

void print_binary(int num){
    if (num <= 0){
        
    }
}

int main(){
    countdown(10);
    countup(10);

    std::cout << std::endl << power(2, 0) << std::endl;
}