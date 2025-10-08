#include <iostream>
#include <sstream>
#include <cmath>
#include "RandomStrategy.h"

template <class T>
RandomStrategy<T>::RandomStrategy(int size) : Storage<T>(size) {
    // TODO: Initialize a, c, m variables
}

template <class T>
void RandomStrategy<T>::addData(T value) {
    // TODO: Find empty spot using random algorithm, add value
}

template <class T>
void RandomStrategy<T>::removeData(T value) {
    // TODO: Find and remove value using random algorithm
}

template <class T>
int RandomStrategy<T>::getIndex(T value) {
    // TODO: Return index of value using random algorithm
    return -1;
}
