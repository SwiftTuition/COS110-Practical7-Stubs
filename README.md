# COS110 Practical 7 - Template Classes & Strategy Pattern

Welcome to Practical 7! This practical focuses on template classes and implementing different traversal strategies using inheritance and polymorphism.

## 📚 What You'll Implement

- **Storage** - Abstract template base class
- **ForwardStrategy** - Linear traversal from front to back
- **ReverseStrategy** - Linear traversal from back to front
- **RandomStrategy** - Traversal using Linear Congruential Generator
- **FibonacciStrategy** - Traversal using Fibonacci sequence

## 🚀 Quick Start with GitHub Codespaces (Recommended)

GitHub Codespaces provides a complete development environment in your browser - no local setup required!

### Step 1: Open in Codespaces

1. Click the green **"Code"** button at the top of this repository
2. Select **"Codespaces"** tab
3. Click **"Create codespace on main"**
4. Wait 30-60 seconds for the environment to build

### Step 2: Verify Setup

Once your Codespace loads, the environment will automatically:
- ✅ Install g++ compiler
- ✅ Install Valgrind for memory leak detection
- ✅ Install Node.js and npm
- ✅ Install Gemini CLI

Check the terminal output to confirm everything installed correctly!

### Step 3: Authenticate Gemini CLI

```bash
# Run this command in the terminal
gemini auth

# Follow the URL that appears and login with your Google account
# Grant the necessary permissions
```

### Step 4: Start Coding!

```bash
# Compile your code (remember: don't compile template .cpp files!)
g++ -Wall -Werror main.cpp -o main

# Run your program
./main

# Check for memory leaks
valgrind --leak-check=full ./main
```

## 💻 Local Development Setup

Prefer working on your own machine? Follow these steps:

### Prerequisites

1. **C++ Compiler (g++)**
   - **Windows:** Install MinGW or Visual Studio
   - **macOS:** Install Xcode Command Line Tools: `xcode-select --install`
   - **Linux:** `sudo apt-get install build-essential`

2. **Valgrind** (for memory leak detection)
   - **Linux:** `sudo apt-get install valgrind`
   - **macOS:** `brew install valgrind`
   - **Windows:** Use WSL (Windows Subsystem for Linux) or Codespaces

### Setting Up Gemini CLI Locally

The Gemini CLI is a powerful AI assistant that can help you understand concepts and debug issues.

#### Step 1: Install Node.js and npm

**Windows:**
1. Download Node.js from [nodejs.org](https://nodejs.org)
2. Run the installer (.msi file)
3. Follow the installation wizard (accept defaults)
4. Restart your computer
5. Verify installation:
   ```cmd
   node --version
   npm --version
   ```

**macOS:**
```bash
# Using Homebrew
brew install node

# Verify
node --version
npm --version
```

**Linux (Ubuntu/Debian):**
```bash
# Install Node.js 18.x
curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
sudo apt-get install -y nodejs

# Verify
node --version
npm --version
```

#### Step 2: Install Gemini CLI

```bash
# Install globally (works on all platforms)
npm install -g @google/generative-ai-cli

# Verify installation
gemini --version
```

**Troubleshooting:**

- **Windows: "npm not recognized"**
  - Close and reopen your terminal/VS Code
  - Restart your computer
  - Check if Node.js is in your PATH (System Environment Variables)

- **macOS/Linux: Permission denied**
  ```bash
  # Option 1: Use sudo
  sudo npm install -g @google/generative-ai-cli

  # Option 2: Change npm prefix
  npm config set prefix ~/.npm-global
  export PATH=~/.npm-global/bin:$PATH
  npm install -g @google/generative-ai-cli
  ```

#### Step 3: Authenticate Gemini

```bash
# Run authentication
gemini auth

# This will open your browser
# Login with your Google account
# Grant the necessary permissions

# Test it works
gemini "Hello! Can you help me with C++ templates?"
```

### Using Gemini CLI in VS Code

1. **Open Terminal:** Press `` Ctrl + ` `` (backtick) or go to View → Terminal
2. **Ask questions:**
   ```bash
   # Understand concepts
   gemini "What is a template class in C++?"

   # Debug errors
   gemini "I'm getting 'invalid use of template-name' - what does this mean?"

   # Understand algorithms
   gemini "Explain how the Linear Congruential Generator formula works"
   ```

**Pro Tips:**
- Use AI to **understand concepts**, not to generate code to copy
- Ask about specific error messages
- Request explanations of algorithms and design patterns
- FitchFork has plagiarism detection - write your own code!

## 📖 What's Included in This Repository

```
stubs/
├── .devcontainer/           # GitHub Codespaces configuration
│   ├── devcontainer.json    # Container setup
│   └── post-create.sh       # Auto-setup script
├── Storage.h/.cpp           # Abstract base class (template)
├── ForwardStrategy.h/.cpp   # Forward traversal strategy
├── ReverseStrategy.h/.cpp   # Reverse traversal strategy
├── RandomStrategy.h/.cpp    # Random (LCG) traversal strategy
├── FibonacciStrategy.h/.cpp # Fibonacci traversal strategy
├── main.cpp                 # Your testing file
├── Practical7_Specs.md      # Full specification
├── Referenced_Figures.md    # UML diagrams explained
├── README.md                # This file
└── SETUP_GEMINI.md          # Detailed Gemini setup guide
```

## 🔨 Compiling Your Code

**Important:** Templates use a special compilation approach!

```bash
# CORRECT - Don't compile template .cpp files directly!
g++ -Wall -Werror main.cpp -o main

# WRONG - This will cause linker errors
g++ -Wall -Werror main.cpp Storage.cpp ForwardStrategy.cpp -o main
```

**Why?** Template implementations are included at the bottom of header files. The compiler generates code for each template instantiation when you use it.

## 🧪 Testing Your Implementation

### Basic Testing

```bash
# Compile and run
g++ -Wall -Werror main.cpp -o main
./main
```

### Memory Leak Detection (10% of grade!)

```bash
# Compile
g++ -Wall -Werror main.cpp -o main

# Run with Valgrind
valgrind --leak-check=full ./main

# Look for this message:
# "All heap blocks were freed -- no leaks are possible"
```

### Testing Coverage (10% of grade!)

```bash
# Compile with coverage flags
g++ --coverage main.cpp -o main

# Run your tests
./main

# Generate coverage report
gcov -f -m -r -j Storage.cpp ForwardStrategy.cpp ReverseStrategy.cpp RandomStrategy.cpp FibonacciStrategy.cpp

# Check coverage percentages
# Target: 60%+ for 80% of testing marks
```

## 📝 Implementation Checklist

### Storage Base Class
- [ ] Constructor allocates `T**` array, initializes to NULL
- [ ] Destructor deletes all non-NULL elements, then deletes array
- [ ] print() outputs `[element1,element2,...]` format with `-` for NULL
- [ ] Pure virtual functions declared (= 0)

### ForwardStrategy
- [ ] Constructor calls parent constructor
- [ ] addData() finds first NULL from front, makes deep copy
- [ ] removeData() finds and deletes first occurrence from front
- [ ] getIndex() searches from front, returns -1 if not found

### ReverseStrategy
- [ ] Same as ForwardStrategy but traverses from back to front
- [ ] All loops go from size-1 down to 0

### RandomStrategy
- [ ] Members a, c, m initialized to correct values
- [ ] All functions reset r to size at start
- [ ] Uses formula: `r = |(a * r + c) % m|`
- [ ] Maximum 3*size iterations

### FibonacciStrategy
- [ ] All functions generate Fibonacci sequence (0, 1, 1, 2, 3, 5, ...)
- [ ] Sequence resets at start of each function
- [ ] Maximum 3*size iterations

### Testing
- [ ] Test all strategies with int, string, double
- [ ] Test edge cases: empty, full, single element
- [ ] Test success and failure cases
- [ ] Aim for 60%+ coverage

### Memory Management
- [ ] Zero memory leaks (Valgrind check)
- [ ] Deep copy in addData: `new T(value)`
- [ ] Delete before setting to NULL in removeData
- [ ] Destructor handles all cleanup

## 🎯 Grading Components

Your submission will be graded on:

| Component | Details |
|-----------|---------|
| **Strategy Implementations** | ForwardStrategy, ReverseStrategy, RandomStrategy, FibonacciStrategy |
| **Memory Management** | Approximately 10% of marks - Valgrind must show zero memory leaks |
| **Testing Coverage** | 10% of assignment marks - Aim for 60%+ coverage to get 80% of testing marks |

**Note:** The exact mark distribution for each strategy is determined by FitchFork test cases. Focus on correct implementation of all four strategies, ensuring zero memory leaks and comprehensive testing.

## 📚 Additional Resources

- **Comprehensive Guide:** Check out the [Practical 7 Guide](../Practical7_Guide/index.html) for detailed explanations
- **Gemini Setup:** See [SETUP_GEMINI.md](SETUP_GEMINI.md) for detailed setup instructions
- **Specification:** [Practical7_Specs.md](Practical7_Specs.md) - official requirements
- **UML Diagrams:** [Referenced_Figures.md](Referenced_Figures.md) - class structure

## 💬 Support

### Swift Tuition Support
- **Email:** admin@swifttuition.co.za
- **WhatsApp:** +27 73 499 6948

### Using Gemini AI
```bash
# Example questions
gemini "What's the difference between T* and T** in templates?"
gemini "Why do I need deep copy instead of shallow copy?"
gemini "Explain the Linear Congruential Generator algorithm"
```

## ⚠️ Important Reminders

1. **C++98 Standard:** Use `NULL` not `nullptr`, no auto keyword
2. **Template Compilation:** Don't compile template .cpp files directly
3. **Deep Copy:** Always use `new T(value)` when adding data
4. **Memory Management:** Run Valgrind frequently during development
5. **Testing:** Write comprehensive tests for 10% of your grade
6. **Plagiarism:** FitchFork checks for copied code - write your own!

## 🎓 Learning Objectives

By completing this practical, you'll master:
- Template class syntax and implementation
- Inheritance with template classes
- Pure virtual functions and abstract classes
- Deep vs shallow copying
- Memory management in template contexts
- Different traversal algorithms
- Testing and debugging strategies

## 🚦 Getting Started Checklist

- [ ] Set up Codespaces OR install local tools
- [ ] Authenticate Gemini CLI
- [ ] Read Practical7_Specs.md
- [ ] Review Referenced_Figures.md (UML diagrams)
- [ ] Read the comprehensive guide
- [ ] Implement Storage base class
- [ ] Implement and test ForwardStrategy
- [ ] Implement and test ReverseStrategy
- [ ] Implement and test RandomStrategy
- [ ] Implement and test FibonacciStrategy
- [ ] Write comprehensive testing main.cpp
- [ ] Run Valgrind - fix all memory leaks
- [ ] Run coverage tests - aim for 60%+
- [ ] Final test before submission

---

**Good luck with Practical 7! 🚀**

*Remember: Start early, test frequently, and use the Gemini CLI when you're stuck on concepts!*
