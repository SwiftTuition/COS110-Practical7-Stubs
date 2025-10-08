#include <iostream>
#include <sstream>
#include <cmath>
#include "RandomStrategy.h"

// Static template member definitions (REQUIRED)
template <class T> int RandomStrategy<T>::a = 1103515245;
template <class T> int RandomStrategy<T>::c = 12345;
template <class T> int RandomStrategy<T>::m = 2147483648;

template <class T>
RandomStrategy<T>::RandomStrategy(int size) : Storage<T>(size) {
    // Constructor - static members already initialized above
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
