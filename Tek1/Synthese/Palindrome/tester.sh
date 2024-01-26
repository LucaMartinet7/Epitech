# test.sh

#!/bin/bash

if [ ! -f "./palindrome" ]; then
    echo "Error: File './palindrome' not found. Please compile using "make functionnal""
    exit 1
fi

# Test 1
output=$(./palindrome -n 4782 -b 10)
expected_output="4782 leads to 46464 in 3 iteration(s) in base 10"
if [ "$output" != "$expected_output" ]; then
    echo "Test 1 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 1 passed"
fi

# Test 2
output=$(./palindrome -n 64 -b 2)
expected_output="64 leads to 65 in 1 iteration(s) in base 2"
if [ "$output" != "$expected_output" ]; then
    echo "Test 2 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 2 passed"
fi

# Test 3
output=$(./palindrome -n 4782 toto)
expected_output="invalid argument"
if [ "$output" != "$expected_output" ]; then
    echo "Test 3 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 3 passed"
fi

# Test 4
output=$(./palindrome -p 363 -b 10)
expected_output=$(cat << EOM
3 leads to 363 in 6 iteration(s) in base 10
6 leads to 363 in 5 iteration(s) in base 10
12 leads to 363 in 4 iteration(s) in base 10
15 leads to 363 in 3 iteration(s) in base 10
21 leads to 363 in 4 iteration(s) in base 10
24 leads to 363 in 3 iteration(s) in base 10
30 leads to 363 in 4 iteration(s) in base 10
33 leads to 363 in 3 iteration(s) in base 10
39 leads to 363 in 2 iteration(s) in base 10
42 leads to 363 in 3 iteration(s) in base 10
48 leads to 363 in 2 iteration(s) in base 10
51 leads to 363 in 3 iteration(s) in base 10
57 leads to 363 in 2 iteration(s) in base 10
60 leads to 363 in 3 iteration(s) in base 10
66 leads to 363 in 2 iteration(s) in base 10
75 leads to 363 in 2 iteration(s) in base 10
84 leads to 363 in 2 iteration(s) in base 10
93 leads to 363 in 2 iteration(s) in base 10
132 leads to 363 in 1 iteration(s) in base 10
231 leads to 363 in 1 iteration(s) in base 10
330 leads to 363 in 1 iteration(s) in base 10
363 leads to 363 in 0 iteration(s) in base 10
EOM
)
if [ "$output" != "$expected_output" ]; then
    echo "Test 4 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 4 passed"
fi

# Test 5
output=$(./palindrome -p 363 -b 10 -imax 2)
expected_output=$(cat << EOM
39 leads to 363 in 2 iteration(s) in base 10
48 leads to 363 in 2 iteration(s) in base 10
57 leads to 363 in 2 iteration(s) in base 10
66 leads to 363 in 2 iteration(s) in base 10
75 leads to 363 in 2 iteration(s) in base 10
84 leads to 363 in 2 iteration(s) in base 10
93 leads to 363 in 2 iteration(s) in base 10
132 leads to 363 in 1 iteration(s) in base 10
231 leads to 363 in 1 iteration(s) in base 10
330 leads to 363 in 1 iteration(s) in base 10
363 leads to 363 in 0 iteration(s) in base 10
EOM
)
if [ "$output" != "$expected_output" ]; then
    echo "Test 5 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 5 passed"
fi

# Test 6
output=$(./palindrome -p 363 -b 10 -imin 6)
expected_output="3 leads to 363 in 6 iteration(s) in base 10"
if [ "$output" != "$expected_output" ]; then
    echo "Test 6 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 6 passed"
fi

# Test 7
output=$(./palindrome -p 363 -b 10 -imin 7)
expected_output="no solution"
if [ "$output" != "$expected_output" ]; then
    echo "Test 7 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 7 passed"
fi

# Test 8
output=$(./palindrome)
expected_output=84
if [ "$expected_output" = "$?" ]; then
    echo "Test 8 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 8 passed"
fi

# Test 9
output=$(./palindrome toto)
expected_output=84
if [ "$expected_output" = "$?" ]; then
    echo "Test 9 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 9 passed"
fi

# Test 10
# output=$(./palindrome -n 4782 -b 2)
# expected_output="4782 leads to 0 in 7 iteration(s) in base 2"
# if [ "$expected_output" = "$?" ]; then
#     echo "Test 10 failed: Expected '$expected_output', but got '$output'"
# else
#     echo "Test 10 passed"
# fi

# Test 11
output=$(./palindrome -n 4782 -b 5)
expected_output="4782 leads to 11868 in 1 iteration(s) in base 5"
if [ "$output" != "$expected_output" ]; then
    echo "Test 11 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 11 passed"
fi

# Test 12
output=$(./palindrome -n 123 -b 8)
expected_output="123 leads to 1530 in 3 iteration(s) in base 8"
if [ "$output" != "$expected_output" ]; then
    echo "Test 12 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 12 passed"
fi

# Test 13
output=$(./palindrome -p 123 -b 10)
expected_output=84
if [ "$expected_output" = "$?" ]; then
    echo "Test 13 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 13 passed"
fi

# Test 14
output=$(./palindrome -p 65 -b 2)
expected_output=$(cat << EOM
64 leads to 65 in 1 iteration(s) in base 2
65 leads to 65 in 0 iteration(s) in base 2
EOM
)
if [ "$output" != "$expected_output" ]; then
    echo "Test 14 failed: Expected '$expected_output', but got '$output'"
else
    echo "Test 14 passed"
fi
