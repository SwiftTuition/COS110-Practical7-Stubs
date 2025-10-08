#include <iostream>
#include <sstream>
#include "ForwardStrategy.h"

template <class T>
ForwardStrategy<T>::ForwardStrategy(int size) : Storage<T>(size) {
    // TODO: Call parent constructor
}

template <class T>
void ForwardStrategy<T>::addData(T value) {
    // TODO: Find empty spot from front, add value
}

template <class T>
void ForwardStrategy<T>::removeData(T value) {
    // TODO: Find and remove value from front
}

template <class T>
int ForwardStrategy<T>::getIndex(T value) {
    // TODO: Return index of value searching from front
    return -1;
}
