#include <iostream>

void printArr(const int* arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void doubleArr(int* arr, int size){
    for (int i = 0; i < size; i++){
        arr[i] *= 2;
    }
}

int* doubleArrNew(const int* arr, int size){
    int* arrNew = new int[size];//Heap allocation
    for (int i = 0; i < size; i++){
        arrNew[i] = arr[i]*2;
    }
    return arrNew;
}

int main(void) {
    const int SIZE = 5;

    int arr[SIZE] = {1, 2, 3, 4, 5};

    printArr(arr, SIZE);
    doubleArr(arr, SIZE);
    printArr(arr, SIZE);
    int* arrNew = doubleArrNew(arr, SIZE); //allocates

    printArr(arrNew, SIZE);
    delete []arrNew;                       //deallocate

    printArr(arrNew, SIZE); //junk data
    
    return 0;
}