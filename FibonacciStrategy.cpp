#include <iostream>
#include <sstream>
#include "FibonacciStrategy.h"

template <class T>
FibonacciStrategy<T>::FibonacciStrategy(int size) : Storage<T>(size) {
    // TODO: Call parent constructor
}

template <class T>
void FibonacciStrategy<T>::addData(T value) {
    // TODO: Find empty spot using Fibonacci algorithm, add value
}

template <class T>
void FibonacciStrategy<T>::removeData(T value) {
    // TODO: Find and remove value using Fibonacci algorithm
}

template <class T>
int FibonacciStrategy<T>::getIndex(T value) {
    // TODO: Return index of value using Fibonacci algorithm
    return -1;
}
