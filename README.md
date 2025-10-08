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

Once your Codespace loads, the environment will automatically install:
- ✅ g++ compiler
- ✅ Valgrind for memory leak detection
- ✅ Node.js and npm (already pre-installed in Codespaces)

Check the terminal output to confirm everything installed correctly!

### Step 3: Upgrade Node.js to Version 20+

**IMPORTANT:** Gemini CLI requires Node.js 20+, but Codespaces comes with Node.js 18. You MUST upgrade first.

```bash
# Check current version
node --version  # Will show v18.x.x

# Upgrade to Node.js 20 using nvm (pre-installed in Codespaces)
nvm install 20
nvm use 20
nvm alias default 20

# Verify upgrade
node --version  # Should now show v20.x.x
```

### Step 4: Install and Setup Gemini CLI

```bash
# Install Gemini CLI globally
npm install -g @google/gemini-cli

# Authenticate with your Google account
gemini auth

# Follow the URL that appears and login with your Google account
# Grant the necessary permissions
```

**Common Error:** If you skip the Node.js upgrade and try to use Gemini, you'll see:
```
ReferenceError: File is not defined
```
This means you need to run the nvm commands above to upgrade to Node.js 20.

### Step 5: Start Coding!

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

#### Step 1: Check Node.js Version

```bash
# Open terminal and check
node --version
npm --version
```

**IMPORTANT:** Gemini CLI requires Node.js **version 20 or higher**. If you have v18 or lower, you need to upgrade.

If you don't have Node.js, or need to upgrade to v20+:

**Windows:**
1. Download **Node.js 20 LTS** from [nodejs.org](https://nodejs.org)
2. Run the installer (.msi file)
3. Restart your computer after installation
4. Verify: `node --version` (should show v20+)

**macOS:**
```bash
# Download Node.js 20 LTS from nodejs.org OR use Homebrew
brew install node@20

# Verify
node --version  # Should show v20+
```

**Linux (Ubuntu/Debian):**
```bash
# Install Node.js 20.x
curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
sudo apt-get install -y nodejs

# Verify
node --version  # Should show v20+
```

#### Step 2: Install Gemini CLI

```bash
# Install globally (works on all platforms)
npm install -g @google/gemini-cli
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

### Using Gemini CLI - Two Modes

**Mode 1: Interactive Chat (Recommended)**

Open Terminal (`` Ctrl + ` `` in VS Code or View → Terminal), then start a chat session:

```bash
# Start interactive chat mode
gemini

# Now you can ask questions naturally:
> What is a template class in C++?
> How does the Linear Congruential Generator work?
> Explain deep copy vs shallow copy
> exit  # Type 'exit' to quit the chat
```

This mode is great for having conversations and asking follow-up questions.

**Mode 2: Single Question**

For quick one-off questions, use quotes:

```bash
# Single question format
gemini "What is a template class in C++?"
gemini "I'm getting 'invalid use of template-name' - what does this mean?"
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
# Interactive chat mode (recommended)
gemini
> What's the difference between T* and T** in templates?
> Why do I need deep copy instead of shallow copy?
> exit

# OR single questions
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
