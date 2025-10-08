# COS 110 Practical 7 - Template Classes & Inheritance (Stubs)

**Swift Tuition - University of Pretoria**
Contact: admin@swifttuition.co.za
WhatsApp Support: +27 73 499 6948

---

## ⚠️ IMPORTANT: ACADEMIC INTEGRITY

These are **STARTER STUBS ONLY** - they contain:
- ✅ Correct file structure
- ✅ Correct function signatures
- ✅ TODO comments guiding implementation
- ❌ **NO algorithmic logic**
- ❌ **NO implementation code**

**You MUST implement all functionality yourself!** Copying implementations from other students or AI-generated code is **plagiarism** and will result in **zero marks**.

---

## 📋 What's Included

### Stub Files (Your Starting Point)
- `Storage.h` & `Storage.cpp` - Abstract base class
- `ForwardStrategy.h` & `ForwardStrategy.cpp` - Forward traversal
- `ReverseStrategy.h` & `ReverseStrategy.cpp` - Reverse traversal
- `RandomStrategy.h` & `RandomStrategy.cpp` - Random (LCG) traversal
- `FibonacciStrategy.h` & `FibonacciStrategy.cpp` - Fibonacci traversal
- `main.cpp` - Basic test file (expand this for testing marks!)

### Specification Files
- `Practical7_Specs.md` - Full assignment specifications
- `Referenced_Figures.md` - UML diagrams and figures
- `out.txt` - Sample expected output

---

## 🚀 Quick Start

### 1. Clone This Repository
```bash
git clone <repository-url>
cd cos110-practical7-stubs
```

### 2. Verify Stubs Compile
```bash
g++ -Werror -Wall main.cpp -o main
./main
```

You should see:
```
=== Basic Stub Test ===
Stubs compiled successfully!
```

### 3. Start Implementing!

Open each `.cpp` file and implement the `// TODO:` sections:

**Example - Storage.cpp:**
```cpp
template <class T>
Storage<T>::Storage(int size) {
    // TODO: Initialize member variables
    // Your code here - initialize data array and size!
}
```

---

## 📚 Implementation Guide

### What You Need to Implement

#### 1. Storage.cpp (Base Class)
- **Constructor**: Allocate `T**` array of given size, fill with `0` (NULL)
- **Destructor**: Delete all allocated memory (no leaks!)
- **print()**: Output format `[elem1,elem2,-]` where `-` represents NULL

#### 2. ForwardStrategy.cpp
- **addData()**: Find first empty slot from **front** (index 0 → size-1)
- **removeData()**: Find and remove value from front
- **getIndex()**: Search from front, return index or -1

#### 3. ReverseStrategy.cpp
- **addData()**: Find first empty slot from **back** (index size-1 → 0)
- **removeData()**: Find and remove value from back
- **getIndex()**: Search from back, return index or -1

#### 4. RandomStrategy.cpp
- **Constructor**: Initialize `a = 1103515245`, `c = 12345`, `m = 2147483648`
- **Algorithm**: Linear Congruential Generator
  - Reset seed to array size each function call
  - Formula: `r = (a * r + c) % m`
  - Max iterations: 3 × array size
  - Use `r % size` as index

#### 5. FibonacciStrategy.cpp
- **Algorithm**: Fibonacci sequence (0, 1, 1, 2, 3, 5, 8, 13...)
  - Reset sequence each function call
  - Max iterations: 3 × array size
  - Use `fibValue % size` as index

#### 6. main.cpp (Testing - Worth 10% of Marks!)
Expand this file with comprehensive tests:
- Test all strategies with different data types (int, double, char)
- Test edge cases (full arrays, empty arrays, not found)
- Test deep copy behavior
- Aim for **high code coverage** (gcov will be used)

---

## 🔑 Critical Implementation Notes

### 1. Function Signatures (MUST MATCH EXACTLY!)
```cpp
// ✅ CORRECT - Takes VALUE
void addData(T value)
void removeData(T value)
int getIndex(T value)

// ❌ WRONG - Don't use pointers in parameters!
void add(T* data)
void remove(T* data)
int getIndex(T* data)
```

### 2. Deep Copy When Adding
```cpp
// ✅ CORRECT - Create new pointer
this->data[i] = new T(value);

// ❌ WRONG - Would be shallow copy
this->data[i] = &value;
```

### 3. Memory Management (10% of Marks!)
- Every `new` must have a `delete`
- Delete in destructor
- Delete when removing elements
- Use `0` instead of `NULL` (C++98)
- **Verify with valgrind**: `valgrind --leak-check=full ./main`

### 4. Value Comparison
```cpp
// ✅ CORRECT - Dereference pointer to compare values
if (this->data[i] != 0 && *(this->data[i]) == value)

// ❌ WRONG - Compares pointer addresses
if (this->data[i] == value)
```

---

## 🛠️ Compilation & Testing

### Compile (Standard Method)
```bash
g++ -Werror -Wall main.cpp -o main
```

**Important**: Only compile `main.cpp`, NOT `*.cpp`! Template classes use a special compilation approach (see spec Section 3).

### Run Your Tests
```bash
./main
```

### Check for Memory Leaks (Critical!)
```bash
valgrind --leak-check=full ./main
```

**Target**: `All heap blocks were freed -- no leaks are possible`

### Test Coverage (for 10% testing marks)
```bash
g++ --coverage main.cpp -o main
./main
gcov -f -m -r -j *.cpp
```

Aim for **60%+ coverage** for full testing marks!

---

## 📦 Submission Checklist

Submit a ZIP file named `uXXXXXXXX.zip` (your student number) containing:

- ✅ `Storage.cpp`
- ✅ `ForwardStrategy.cpp`
- ✅ `ReverseStrategy.cpp`
- ✅ `RandomStrategy.cpp`
- ✅ `FibonacciStrategy.cpp`
- ✅ `main.cpp`

**DO NOT submit**:
- ❌ `.h` files (FitchFork will use their own)
- ❌ Compiled files (`.o`, executables)
- ❌ IDE files

Files must be in the **root** of the ZIP, not in a subfolder!

---

## 🎯 Grading Breakdown

| Component | Marks | Notes |
|-----------|-------|-------|
| ForwardStrategy | 28% | Correct traversal implementation |
| ReverseStrategy | 28% | Correct traversal implementation |
| RandomStrategy | 28% | Correct LCG algorithm |
| FibonacciStrategy | 28% | Correct Fibonacci algorithm |
| **Memory Management** | **10%** | **No leaks with valgrind!** |
| **Testing Coverage** | **10%** | **Comprehensive main.cpp** |

**Total**: 132% (scaled to 100%)

---

## 💡 Tips for Success

1. **Start Early**: Template classes are complex!
2. **Test Incrementally**: Implement one strategy at a time
3. **Use print() for Debugging**: See what's in your array
4. **Check Memory Always**: Run valgrind frequently
5. **Read the Spec Carefully**: Section 4 has all algorithm details
6. **Ask for Help**: Use consultation sessions if stuck

---

## 📧 Support

**Swift Tuition Support Channels:**
- 📧 Email: admin@swifttuition.co.za
- 💬 WhatsApp: +27 73 499 6948
- 🎥 YouTube: [Swift Tuition Channel](https://youtube.com/@swifttuition)

**Course Resources:**
- Lecture Slides: Week 9 (Templates), Week 10 (Linked Lists)
- Tutorial: Tutorial 8 exercises
- Past Papers: Practice with EO2/EO3 questions

---

## ⚖️ Academic Integrity Reminder

**These stubs are provided to help you learn, not to copy!**

✅ **Allowed:**
- Using these stubs as your starting structure
- Discussing algorithms with classmates
- Asking tutors for guidance
- Using lecture notes and textbook

❌ **NOT Allowed (= Plagiarism = 0 marks):**
- Copying implementations from other students
- Using AI to generate implementation code
- Submitting code you don't understand
- Sharing your completed code with others

**You MUST write your own implementation logic!**

---

## 📄 License

These stubs are provided by **Swift Tuition** for educational purposes only.
© 2024 Swift Tuition. All rights reserved.

For COS 110 students at the University of Pretoria.

---

**Good luck! You've got this! 🚀**
