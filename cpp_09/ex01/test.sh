
#!/bin/bash

test_rpn() {
    local expression="$1"
    local expected="$2"

    result=$(./RPN "$expression" 2>&1)
    
    echo "  '$expression'"
    echo "   Expected: $expected"
    echo "   Got:      $result"
}

echo "=== Subject Tests ==="
test_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
test_rpn "7 7 * 7 -" "42"
test_rpn "1 2 * 2 / 2 * 2 4 - +" "0"
test_rpn "(1 + 1)" "Error"

echo "=== Valid tests ==="
test_rpn "3 5 +" "8"
test_rpn "8 2 -" "6"
test_rpn "4 3 *" "12"
test_rpn "9 3 /" "3"
test_rpn "3 5 + 2 *" "16"
test_rpn "5 1 2 + 4 * + 3 -" "14"
test_rpn "7" "7"

echo
echo "=== Invalid tests ==="
test_rpn "3 5 + 4 7 6" "Error"
test_rpn "3 +" "Error"
test_rpn "+" "Error"
test_rpn "3 0 /" "Error"
test_rpn "3 5" "Error"
test_rpn "abc" "Error"
test_rpn "" "Error"
test_rpn "'sdfsdf' 'sdsd'" "Error"
test_rpn
