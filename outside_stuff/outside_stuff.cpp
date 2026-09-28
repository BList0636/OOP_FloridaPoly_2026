#include <iostream>
#include <vector>

std::vector<int> combineArrays(const int arr1[], const int arr2[], const int arr3[], int size1, int size2, int size3){
    std::vector<int> output;
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;

    while (true){
        if (pos1 != size1 && (pos2 == size2 || arr1[pos1] < arr2[pos2]) && (pos3 == size3 || arr1[pos1] < arr2[pos2])){
            //1 is smallest
            output.push_back(arr1[pos1]);
            pos1++;
        }
        else if (pos2 != size2 && (pos3 == size3 || arr2[pos2] < arr3[pos3])){
            //2 is smallest
            output.push_back(arr2[pos2]);
            pos2++;
        }
        else if (pos3 != size3){
            //3 is smallest
            output.push_back(arr3[pos3]);
            pos3++;
        }
        else{
            break;
        }
    }

    return output;
}

void printVector(std::vector<int> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr3[] = {1,4,7};
    int arr2[] = {2,5,8};
    int arr1[] = {3,6,9};

    std::vector<int> output(combineArrays(arr1,arr2,arr3,3,3,3));

    printVector(output);
}