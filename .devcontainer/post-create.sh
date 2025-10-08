#!/bin/bash

echo "========================================="
echo "  COS110 Practical 7 - Setup Starting  "
echo "========================================="
echo ""

# Update package lists
echo "📦 Updating package lists..."
sudo apt-get update -qq

# Install essential build tools
echo "🔨 Installing build tools..."
sudo apt-get install -y build-essential g++ valgrind > /dev/null 2>&1

# Verify g++ installation
echo "✓ g++ version:"
g++ --version | head -n 1

# Install Node.js and npm (already included via features, but verify)
echo ""
echo "📦 Verifying Node.js and npm..."
node --version
npm --version

# Install Gemini CLI globally
echo ""
echo "🤖 Installing Gemini CLI..."
npm install -g @google/generative-ai-cli

# Verify Gemini CLI installation
if command -v gemini &> /dev/null; then
    echo "✓ Gemini CLI installed successfully!"
else
    echo "⚠ Gemini CLI installation may have failed. Try running: npm install -g @google/generative-ai-cli"
fi

echo ""
echo "========================================="
echo "  Setup Complete! 🎉                   "
echo "========================================="
echo ""
echo "Next steps:"
echo "1. Authenticate Gemini CLI: gemini auth"
echo "2. Compile your code: g++ -Wall -Werror main.cpp -o main"
echo "3. Run your program: ./main"
echo "4. Check for memory leaks: valgrind --leak-check=full ./main"
echo ""
echo "Need help? Check README.md or SETUP_GEMINI.md"
echo "========================================="
