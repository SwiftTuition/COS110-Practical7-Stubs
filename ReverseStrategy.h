#ifndef REVERSESTRATEGY_H
#define REVERSESTRATEGY_H

#include "Storage.h"

template <class T>
class ReverseStrategy : public Storage<T> {
public:
    ReverseStrategy(int size);
    virtual void addData(T value);
    virtual void removeData(T value);
    virtual int getIndex(T value);
};

#include "ReverseStrategy.cpp"
#endif
