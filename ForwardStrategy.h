#ifndef FORWARDSTRATEGY_H
#define FORWARDSTRATEGY_H

#include "Storage.h"

template <class T>
class ForwardStrategy : public Storage<T> {
public:
    ForwardStrategy(int size);
    virtual void addData(T value);
    virtual void removeData(T value);
    virtual int getIndex(T value);
};

#include "ForwardStrategy.cpp"
#endif
