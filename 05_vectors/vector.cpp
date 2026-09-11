#include <vector>
#include <iostream>

void printVector(std::vector<int> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

void printVectorBackward(std::vector<int> v){
    for (int i = v.size() - 1; i >= 0; i--){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}


int main(){
    std::vector<int> v1 = {1,1,1,1};
    std::vector<int> v2 = {1,2,3};
    std::vector<int> v3 = {10,2};
    std::vector<int> v4(v2);

    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
}