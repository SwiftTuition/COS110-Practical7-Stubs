#ifndef FIBONACCISTRATEGY_H
#define FIBONACCISTRATEGY_H

#include "Storage.h"

template <class T>
class FibonacciStrategy : public Storage<T> {
public:
    FibonacciStrategy(int size);
    virtual void addData(T value);
    virtual void removeData(T value);
    virtual int getIndex(T value);
};

#include "FibonacciStrategy.cpp"
#endif
