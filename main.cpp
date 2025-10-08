#include "FibonacciStrategy.h"
#include "ForwardStrategy.h"
#include "RandomStrategy.h"
#include "ReverseStrategy.h"
#include "Storage.h"
#include <iostream>

using namespace std;

int main() {
    // TODO: Add your test cases here

    cout << "=== Basic Stub Test ===" << endl;

    ForwardStrategy<int> fs(5);
    fs.print();

    cout << "Stubs compiled successfully!" << endl;

    return 0;
}
