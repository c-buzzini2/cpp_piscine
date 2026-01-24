#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Compile the program
echo "Compiling..."
make
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}"
echo ""

PROGRAM="./zombieHorde"

# Test cases:
echo "Running tests..."
echo "----------------------------------------"

# Test 1
echo "Test 1: No arguments"
$PROGRAM
echo ""

# Test 2
echo "Test 2: Single argument"
$PROGRAM 15
echo ""

# Test 3
echo "Test 3: Multiple arguments"
$PROGRAM 15 Greta sdafsadf
echo ""

# Test 4
echo "Test 4: Non-numeric arg[1]"
$PROGRAM 10d Greta
echo ""

# Test 5
echo "Test 5: Negative arg[1]"
$PROGRAM -10 Greta
echo ""

# Test 6
echo "Test 6: 100 OK"
$PROGRAM 100 Greta
echo ""

# Test 7
echo "Test 7: max int "
$PROGRAM 2147483647 Greta
echo ""

# Test 8
echo "Test 8: long "
$PROGRAM 2147483648 Greta
echo ""

# Test 9
echo "Test 9: zero "
$PROGRAM 0 Greta
echo ""

# Test 10
echo "Test 10: empty string"
$PROGRAM 5 ""
echo ""

echo "----------------------------------------"
echo "All tests completed!"