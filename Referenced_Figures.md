### Figure 1: Class diagrams

This figure contains a UML diagram illustrating the relationship between five classes.

An abstract parent class `Storage` is at the top. Four classes inherit from `Storage`: `FibonacciStrategy`, `ForwardStrategy`, `RandomStrategy`, and `ReverseStrategy`.

**Class: Storage**
*   Template: `T: class`
*   Protected Members:
    *   `#data: T**`
    *   `#size: int`
*   Public Functions:
    *   `+Storage(size: int)`
    *   `+~Storage()`
    *   `+print(): void`
    *   `+addData(value: T): void`
    *   `+removeData(value: T): void`
    *   `+getIndex(value: T): int`

**Class: FibonacciStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+FibonacciStrategy(size: int)`
    *   `+addData(value: T): void`
    *   `+removeData(value: T): void`
    *   `+getIndex(value: T): int`

**Class: ForwardStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+ForwardStrategy(size: int)`
    *   `+addData(value: T): void`
    *   `+removeData(value: T): void`
    *   `+getIndex(value: T): int`

**Class: RandomStrategy**
*   Template: `T: class`
*   Private Members:
    *   `-a: int`
    *   `-c: int`
    *   `-m: int`
*   Public Functions:
    *   `+RandomStrategy(size: int)`
    *   `+addData(value: T): void`
    *   `+removeData(value: T): void`
    *   `+getIndex(value: T): int`

**Class: ReverseStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+ReverseStrategy(size: int)`
    *   `+addData(value: T): void`
    *   `+removeData(value: T): void`
    *   `+getIndex(value: T): int`

### Figure 2: Storage UML

This figure details the `Storage` class.

**Class: Storage**
*   Template: `T: class`
*   Protected Members:
    *   `#data: T**`
    *   `#size: int`
*   Public Functions:
    *   `+Storage(size: int)`
    *   `+~Storage()`
    *   `+print(): void`
    *   `+addData(value : T) : void`
    *   `+removeData(value : T) : void`
    *   `+getIndex(value : T) : int`

### Figure 3: ForwardStrategy UML

This figure details the `ForwardStrategy` class.

**Class: ForwardStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+ForwardStrategy(size: int)`
    *   `+addData(value : T) : void`
    *   `+removeData(value : T) : void`
    *   `+getIndex(value: T): int`

### Figure 4: ReverseStrategy UML

This figure details the `ReverseStrategy` class.

**Class: ReverseStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+ReverseStrategy(size: int)`
    *   `+addData(value : T) : void`
    *   `+removeData(value : T) : void`
    *   `+getIndex(value: T): int`

### Figure 5: RandomStrategy UML

This figure details the `RandomStrategy` class.

**Class: RandomStrategy**
*   Template: `T: class`
*   Private Members:
    *   `-a: int`
    *   `-c: int`
    *   `-m: int`
*   Public Functions:
    *   `+RandomStrategy(size : int)`
    *   `+addData(value : T) : void`
    *   `+removeData(value : T) : void`
    *   `+getIndex(value : T) : int`

### Figure 6: FibonacciStrategy UML

This figure details the `FibonacciStrategy` class.

**Class: FibonacciStrategy**
*   Template: `T: class`
*   Public Functions:
    *   `+FibonacciStrategy(size : int)`
    *   `+addData(value : T) : void`
    *   `+removeData(value : T) : void`
    *   `+getIndex(value : T) : int`