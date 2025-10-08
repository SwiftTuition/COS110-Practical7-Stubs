#include <iostream>
#include <sstream>
#include "ReverseStrategy.h"

template <class T>
ReverseStrategy<T>::ReverseStrategy(int size) : Storage<T>(size) {
    // TODO: Call parent constructor
}

template <class T>
void ReverseStrategy<T>::addData(T value) {
    // TODO: Find empty spot from back, add value
}

template <class T>
void ReverseStrategy<T>::removeData(T value) {
    // TODO: Find and remove value from back
}

template <class T>
int ReverseStrategy<T>::getIndex(T value) {
    // TODO: Return index of value searching from back
    return -1;
}
