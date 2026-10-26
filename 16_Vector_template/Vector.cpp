#include "Vector.hpp"
#include <iostream>
#include <climits> 


Vector::Vector(int capacity) : size(0), capacity(capacity) {
    data = new int[capacity];
}

Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];

    // Copy the data from the vector other
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}   

Vector::~Vector() {
    if (data) {
        delete [] data;
    }
}

void Vector::print() const {
    std::cout << "[ ";
    // Print the data
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << "]\n";
}

void Vector::push_back(int val) {
    if (full()) {
        allocateMemory(capacity * 2);
    }
    
    data[size] = val;
    size++;

}


bool Vector::full() const {
    return size == capacity;
}

void Vector::allocateMemory(int new_capacity) {
    capacity = new_capacity;
    // Save the address of an old array
    int* old_data = data;

    // Allocate the new memory
    data = new int[capacity];
    
    // Copy the data
    for (int i = 0; i < size; i++) {
        data[i] = old_data[i];
    }

    // Deallocate the old memory
    delete [] old_data;

}


void Vector::pop_back() {
    if (empty()) {
        return;
    }
    --size;
}

bool Vector::empty() const {
    return size == 0;
}

int Vector::at(int index) const {
    if (index < size * -1 || index > size - 1) {
        throw "Invalid index";
    }
    if (index >= 0) {
        return data[index];
    }
    else {
        return data[size - (index * -1)];
    }
}

int Vector::getCapacity() const {
    return capacity;
}

void Vector::clear() {
    delete [] data;
    size = 0;
    capacity = 10;
    
    data = new int[capacity];
}

int Vector::getSize() const {
    return size;
}

void Vector::push_front(int value) {
    if (size >= capacity) {
        allocateMemory(capacity * 2);
    }
    for (int i = size; i >= 1; i--) {
        data[i] = data[i - 1]; 
    }
    data[0] = value;
    size++;
}

void Vector::insert(int pos, int value) {
    if (size == 0 && pos == -1) {
        push_back(value);
        return;
    }
    if (pos < size * -1  || pos > size - 1) {
        throw "Invalid index";
    }
    if (size >= capacity) {
        allocateMemory(capacity * 2);
    }
    if (pos < 0) {
        pos = size - (pos * -1);
    }
    for (int i = size; i >= pos; i--) {
        data[i] = data[i - 1]; 
    }
    data[pos] = value;
    size++;
}