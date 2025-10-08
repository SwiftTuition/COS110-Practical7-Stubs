#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include "Storage.h"
#include <cmath>

template <class T>
class RandomStrategy : public Storage<T> {
private:
    static int a;
    static int c;
    static int m;

public:
    RandomStrategy(int size);
    virtual void addData(T value);
    virtual void removeData(T value);
    virtual int getIndex(T value);
};

#include "RandomStrategy.cpp"
#endif
