# Gemini CLI Setup Guide

This guide provides detailed instructions for setting up the Gemini CLI assistant in both GitHub Codespaces and local development environments (Windows, macOS, Linux).

## Table of Contents

- [What is Gemini CLI?](#what-is-gemini-cli)
- [Codespaces Setup](#codespaces-setup)
- [Local Setup - Windows](#local-setup---windows)
- [Local Setup - macOS](#local-setup---macos)
- [Local Setup - Linux](#local-setup---linux)
- [VS Code Integration](#vs-code-integration)
- [Using Gemini CLI](#using-gemini-cli)
- [Troubleshooting](#troubleshooting)

---

## What is Gemini CLI?

Gemini CLI is a command-line interface for Google's Gemini AI. It's like having a tutor available 24/7 right in your terminal. You can:

- Ask questions about C++ concepts
- Get explanations of error messages
- Understand algorithms and design patterns
- Debug issues in your code
- Learn about template classes, inheritance, and more

**Important:** Use Gemini to **understand concepts**, not to generate code to copy. FitchFork has plagiarism detection!

---

## Codespaces Setup

If you're using GitHub Codespaces, the setup is mostly automatic!

### Step 1: Open Codespace

1. Go to the repository on GitHub
2. Click green **"Code"** button
3. Select **"Codespaces"** → **"Create codespace on main"**
4. Wait for environment to load (30-60 seconds)

### Step 2: Check Node.js Version

GitHub Codespaces comes with Node.js pre-installed, but it's usually v18. Gemini CLI requires v20+.

```bash
node --version  # Will likely show v18.x.x
npm --version
```

### Step 3: Upgrade to Node.js 20

**REQUIRED:** Use nvm (pre-installed in Codespaces) to upgrade:

```bash
# Install Node.js 20
nvm install 20
nvm use 20
nvm alias default 20

# Verify upgrade
node --version  # Should now show v20.x.x
```

### Step 4: Install Gemini CLI

```bash
# Install Gemini CLI globally
npm install -g @google/gemini-cli

# Verify installation
gemini --version
```

### Step 5: Authenticate

```bash
# Run authentication command
gemini auth

# This will display a URL - click it or copy-paste to browser
# Example: https://accounts.google.com/o/oauth2/v2/auth?...

# Login with your Google account
# Grant the requested permissions

# Return to terminal - you should see:
# "Authentication successful!"
```

### Step 6: Test

**Interactive Chat Mode (Recommended):**
```bash
# Start interactive chat
gemini

# Ask questions naturally
> Hello! Can you help me with C++ templates?
> What is a pure virtual function?
> exit  # Type 'exit' to quit
```

**Single Question Mode:**
```bash
# Quick questions
gemini "Explain template classes in C++"
```

**Common Error:** If you get `ReferenceError: File is not defined`, you skipped Step 3. Go back and upgrade to Node.js 20.

**Done!** You're ready to use Gemini CLI in Codespaces.

---

## Local Setup - Windows

### Step 1: Install Node.js and npm

1. **Download Node.js**
   - Go to [https://nodejs.org](https://nodejs.org)
   - Download the **LTS (Long Term Support)** version
   - Choose the Windows Installer (.msi) - 64-bit

2. **Run the Installer**
   - Double-click the downloaded .msi file
   - Click "Next" through the setup wizard
   - **Important:** Make sure "Add to PATH" is checked
   - Accept the license agreement
   - Choose default installation location
   - Complete the installation

3. **Restart Your Computer**
   - This ensures PATH changes take effect

4. **Verify Installation**
   - Open Command Prompt (Win + R, type `cmd`, press Enter)
   - Run these commands:
   ```cmd
   node --version
   npm --version
   ```
   - You should see version numbers (e.g., v18.17.0 and 9.6.7)

### Step 2: Install Gemini CLI

```cmd
# Open Command Prompt (Admin not required, but may help)

# Install Gemini CLI globally
npm install -g @google/gemini-cli

# This may take 1-2 minutes
# Wait for "added X packages" message
```

### Step 3: Verify Installation

```cmd
# Check if gemini command is available
gemini --version

# If you get an error, try closing and reopening Command Prompt
```

### Step 4: Authenticate

```cmd
# Run authentication
gemini auth

# A URL will appear in the terminal
# Copy the full URL and paste into your browser
# Or Ctrl+Click if your terminal supports it

# Login with your Google account
# Grant the permissions requested

# Return to Command Prompt
# You should see "Authentication successful!"
```

### Step 5: Test in VS Code

1. Open VS Code
2. Open your project folder
3. Open Terminal (Ctrl + `)
4. Select PowerShell or Command Prompt from dropdown
5. Try interactive chat:
   ```cmd
   gemini
   > What is a template class in C++?
   > exit
   ```

   OR single questions:
   ```cmd
   gemini "What is a template class in C++?"
   ```

**Troubleshooting Windows:**

- **"npm not recognized"**
  - Close and reopen Command Prompt/VS Code
  - Restart your computer
  - Check System Environment Variables → PATH includes Node.js

- **"gemini not recognized"**
  - Close and reopen terminal
  - Try: `npm install -g @google/generative-ai-cli` again
  - Check if npm global bin is in PATH

---

## Local Setup - macOS

### Step 1: Install Node.js and npm

**Option 1: Using Homebrew (Recommended)**

```bash
# Install Homebrew if you don't have it
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install Node.js (includes npm)
brew install node

# Verify installation
node --version
npm --version
```

**Option 2: Using Official Installer**

1. Go to [https://nodejs.org](https://nodejs.org)
2. Download macOS Installer (.pkg)
3. Run the installer
4. Follow the setup wizard
5. Verify in Terminal:
   ```bash
   node --version
   npm --version
   ```

### Step 2: Install Gemini CLI

```bash
# Install globally
npm install -g @google/generative-ai-cli

# If you get permission errors, use sudo:
sudo npm install -g @google/generative-ai-cli
```

### Step 3: Verify Installation

```bash
# Check version
gemini --version

# If command not found, try closing and reopening Terminal
```

### Step 4: Authenticate

```bash
# Run authentication
gemini auth

# Click the URL that appears (Cmd+Click)
# Or copy-paste to browser

# Login with Google account
# Grant permissions

# Return to Terminal
# You should see "Authentication successful!"
```

### Step 5: Test in VS Code

1. Open VS Code
2. Open Terminal (Ctrl + `)
3. Try:
   ```bash
   gemini "Explain template classes in C++"
   ```

**Troubleshooting macOS:**

- **Permission denied during install**
  ```bash
  # Option 1: Use sudo
  sudo npm install -g @google/generative-ai-cli

  # Option 2: Change npm prefix (no sudo needed)
  npm config set prefix ~/.npm-global
  export PATH=~/.npm-global/bin:$PATH
  npm install -g @google/generative-ai-cli
  ```

- **Command not found**
  - Close and reopen Terminal
  - Check if npm global bin is in PATH: `echo $PATH`

---

## Local Setup - Linux (Ubuntu/Debian)

### Step 1: Install Node.js and npm

```bash
# Update package lists
sudo apt-get update

# Install Node.js 18.x (LTS)
curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
sudo apt-get install -y nodejs

# Verify installation
node --version
npm --version
```

### Step 2: Install Gemini CLI

```bash
# Install globally
npm install -g @google/generative-ai-cli

# If permission errors:
sudo npm install -g @google/generative-ai-cli --unsafe-perm=true
```

### Step 3: Verify Installation

```bash
# Check version
gemini --version
```

### Step 4: Authenticate

```bash
# Run authentication
gemini auth

# Click or copy-paste the URL
# Login with Google account
# Grant permissions

# Return to terminal
# Should see "Authentication successful!"
```

### Step 5: Test in VS Code

```bash
# In VS Code terminal
gemini "What are pure virtual functions?"
```

**Troubleshooting Linux:**

- **Permission denied**
  ```bash
  # Option 1: Use sudo
  sudo npm install -g @google/generative-ai-cli

  # Option 2: Change npm prefix
  npm config set prefix ~/.npm-global
  echo 'export PATH=~/.npm-global/bin:$PATH' >> ~/.bashrc
  source ~/.bashrc
  npm install -g @google/generative-ai-cli
  ```

- **Node.js version issues**
  ```bash
  # Remove old Node.js first
  sudo apt-get remove nodejs
  # Then follow Step 1 again
  ```

---

## VS Code Integration

### Opening Terminal in VS Code

- **Keyboard:** Ctrl + ` (backtick) or Ctrl + Shift + `
- **Menu:** View → Terminal
- **Command Palette:** Ctrl+Shift+P → "Terminal: Create New Terminal"

### Selecting Shell (Windows)

1. Click dropdown in terminal panel
2. Choose:
   - Command Prompt
   - PowerShell
   - Git Bash (if installed)

### Using Gemini in VS Code

```bash
# Ask questions directly in terminal
gemini "question here"

# Multi-line questions with quotes
gemini "Explain the difference between:
1. T* (pointer to T)
2. T** (pointer to pointer to T)"

# Pipe file contents (advanced)
cat mycode.cpp | gemini "Find bugs in this code"
```

### Tips

- Keep VS Code terminal open while coding
- Ask questions as they come up
- Use Gemini to explain error messages
- Request clarification on spec requirements

---

## Using Gemini CLI

### Two Usage Modes

**Mode 1: Interactive Chat (Recommended)**

Start a conversation and ask multiple questions:

```bash
# Start interactive mode
gemini

# Now you can chat naturally:
> What is a template class?
> Can you explain that with an example?
> What's the difference between T* and T**?
> exit  # Quit the chat
```

This mode is great for:
- Having a conversation with follow-up questions
- Exploring topics in depth
- Getting clarifications

**Mode 2: Single Question**

For quick one-off questions:

```bash
# Quick questions
gemini "What is a template class?"
gemini "Explain the Linear Congruential Generator algorithm"
gemini "I'm getting 'invalid use of template-name' error. What does this mean?"
gemini "What's the difference between deep copy and shallow copy?"
```

This mode is great for:
- Quick lookups
- Specific error messages
- Using in scripts

### Best Practices

**DO:**
- ✅ Ask about concepts and theory
- ✅ Request explanations of error messages
- ✅ Ask for algorithm explanations
- ✅ Request clarification on specifications
- ✅ Ask about best practices
- ✅ Seek debugging strategies

**DON'T:**
- ❌ Copy-paste AI-generated code directly
- ❌ Ask AI to "write the function for me"
- ❌ Submit AI-generated code as your own
- ❌ Use AI to bypass learning

### Example Questions for This Practical

```bash
# Understanding templates
gemini "How do I declare a template class in C++?"

# Memory management
gemini "Why do I need to delete each element before deleting the array?"

# Algorithms
gemini "Walk me through how the Fibonacci strategy should work"

# Debugging
gemini "My code compiles but segfaults. What are common causes of segfaults with pointers?"

# Specifications
gemini "What does 'pure virtual function' mean and how do I implement it?"

# Testing
gemini "How do I write comprehensive tests for template classes?"
```

---

## Troubleshooting

### General Issues

**Problem:** `command not found: gemini`

**Solutions:**
1. Close and reopen terminal/VS Code
2. Restart computer
3. Reinstall: `npm install -g @google/generative-ai-cli`
4. Check PATH includes npm global bin directory

---

**Problem:** `npm: command not found`

**Solutions:**
1. Install Node.js (includes npm)
2. Restart terminal after installation
3. Check Node.js installation: `which node` (Mac/Linux) or `where node` (Windows)

---

**Problem:** Permission denied during installation

**Solutions:**

*Linux/macOS:*
```bash
# Option 1: Use sudo
sudo npm install -g @google/generative-ai-cli

# Option 2: Change npm prefix
mkdir ~/.npm-global
npm config set prefix ~/.npm-global
echo 'export PATH=~/.npm-global/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
npm install -g @google/generative-ai-cli
```

*Windows:*
- Run Command Prompt as Administrator
- Or install Node.js again with "Run as Administrator"

---

**Problem:** Authentication fails or doesn't open browser

**Solutions:**
1. Copy the full URL manually and paste in browser
2. Make sure you're using a Google account
3. Try clearing browser cache and cookies
4. Try different browser
5. Check internet connection

---

**Problem:** Gemini gives errors or doesn't respond

**Solutions:**
1. Check internet connection
2. Re-authenticate: `gemini auth`
3. Update Gemini CLI: `npm update -g @google/generative-ai-cli`
4. Check Gemini API status (Google outages rare but possible)

---

### Platform-Specific Issues

**Windows: "The system cannot find the path specified"**
- Restart VS Code/Command Prompt
- Check PATH environment variables
- Reinstall Node.js ensuring "Add to PATH" is checked

**macOS: "gyp: No Xcode or CLT version detected"**
```bash
# Install Xcode Command Line Tools
xcode-select --install
```

**Linux: "EACCES: permission denied"**
```bash
# Fix npm permissions
sudo chown -R $USER:$(id -gn $USER) ~/.npm
sudo chown -R $USER:$(id -gn $USER) ~/.config
```

---

## Getting Help

### Swift Tuition Support
- **Email:** admin@swifttuition.co.za
- **WhatsApp:** +27 73 499 6948

### Useful Resources
- [Node.js Documentation](https://nodejs.org/docs)
- [npm Documentation](https://docs.npmjs.com)
- [Gemini API Documentation](https://ai.google.dev)

---

## Quick Reference Card

```bash
# Installation
npm install -g @google/gemini-cli

# Authentication
gemini auth

# Check version
gemini --version

# Interactive chat mode
gemini

# Single question mode
gemini "your question here"

# Help
gemini --help

# Update Gemini CLI
npm update -g @google/gemini-cli
```

---

**Happy coding! Remember to use AI responsibly - it's a learning tool, not a code generator!** 🚀
