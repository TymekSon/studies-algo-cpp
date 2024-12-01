#pragma once

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include <string>

template <typename T>

class DynamicArray {

private:
    struct Element {
        T value;

        Element(const T& v) : value(v) {}

        Element() : value() {}

        void get() {
            return value;
        }

        void set(T input) {
            value = input;
        }

        void display() {
            std::cout << value << std::endl;
        }

        std::string str() {
            try {
                return std::to_string(value);
            }
            catch(...){
                throw;
                return 0;
            }
        }
    };

    Element * array;               
    int size;              
    int capacity; 

    void expand(int expandedCapacity) {
        Element * new_array = new Element[expandedCapacity];
        for (int i = 0; i < size; ++i) {
                new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = expandedCapacity;
    }

public:
    typename std::enable_if<std::is_arithmetic<T>::value, std::string>::type
        to_string(const T& value) {
        return std::to_string(value);
    }

    DynamicArray() : size(0), capacity(1) {
        array = new Element[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void add(T value) {
        if (size >= capacity) {
            expand(static_cast<int>(capacity * 2.0)); 
        }
        array[size++].set(value);
    }

    Element get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index].get();
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        array[index].set(value);
    }

    void clear() {
        delete[] array;
        size = 0;
        capacity = 1;
        array = new Element[capacity];
    }

    std::string toString(int toDisplay = 10) const {
        std::string result = "Array(size=" + std::to_string(size) +
            ", capacity=" + std::to_string(capacity) + ")10 first elements: ";
        int count = std::min(size, toDisplay);
        for (int i = 0; i < count; ++i) {
            result += array[i].str() + " ";
        }
        return result;
    }

    void sort(bool ascending = true) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if ((ascending && array[j].get() > array[j + 1].get()) || (!ascending && array[j].get() < array[j + 1].get())) {
                    std::swap(array[j], array[j + 1]);
                }
            }
        }
    }

    int getSize() const { return size; }

    int getCapacity() const { return capacity; }
};