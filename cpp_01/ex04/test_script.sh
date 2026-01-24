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

PROGRAM="./my_sed"

# Test cases:
echo "Running tests..."
echo "----------------------------------------"

# Test 0
echo "Test 0: Should work"
$PROGRAM test.txt ello i
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 1
echo "Test 1: No arguments"
$PROGRAM
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 2
echo "Test 2: Single argument"
$PROGRAM test.txt
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 3
echo "Test 3: Multiple arguments"
$PROGRAM test.txt ello i sdfsdfsdfsd
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 4
echo "Test 4: Non-existing file"
$PROGRAM test ello i
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 5
echo "Test 5: No reading permission"
chmod -r test.txt
$PROGRAM test.txt ello i
chmod +r test.txt
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 6
echo "Test 6: File empty string"
$PROGRAM "" ello i
cat test.txt.replace
rm test.txt.replace
echo "" 

# Test 7
echo "Test 7: search for empty string"
$PROGRAM test.txt "" i
cat test.txt.replace
rm test.txt.replace
echo ""

# Test 8
echo "Test 8: replace with empty string "
$PROGRAM test.txt ello ""
cat test.txt.replace
rm test.txt.replace
echo ""

echo "----------------------------------------"
echo "All tests completed!"