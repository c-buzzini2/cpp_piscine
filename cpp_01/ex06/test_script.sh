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

PROGRAM=./harlFilter

# Test cases:
echo "Running tests..."
echo "----------------------------------------"

# Test 1
echo "Test 1: No arguments"
$PROGRAM
echo ""

# Test 2
echo "Test 2: Single argument - invalid"
$PROGRAM DEBUGINFO
echo ""

# Test 3
echo "Test 3: Multiple arguments"
$PROGRAM DEBUG DEBUG
echo ""

# Test 4
echo "Test 4: DEBUG - prints all 4"
$PROGRAM DEBUG
echo ""

# Test 5
echo "Test 5: INFO - prints 3"
$PROGRAM INFO
echo ""

# Test 6
echo "Test 6: WARNING - prints 2"
$PROGRAM WARNING
echo ""

# Test 7
echo "Test 7: ERROR - prints 1"
$PROGRAM ERROR
echo ""

echo "----------------------------------------"
echo "All tests completed!"