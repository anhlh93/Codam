#!/bin/bash

# Colors for better readability
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counter for tracking test results
PASSED=0
FAILED=0
TOTAL=0

# Function to print section headers
print_header() {
    echo -e "\n${BLUE}==== $1 ====${NC}"
}

# Function to run test and check results
run_test() {
    TEST_NUM=$((TOTAL+1))
    TOTAL=$TEST_NUM
    TEST_NAME=$1
    shift
    
    echo -e "\n${YELLOW}Test $TEST_NUM: $TEST_NAME${NC}"
    
    # Run the actual test (passed as function arguments)
    "$@"
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ Test $TEST_NUM: PASSED${NC}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}✗ Test $TEST_NUM: FAILED${NC}"
        FAILED=$((FAILED+1))
    fi
}

# Function to compare files and return appropriate exit code
compare_files() {
    if diff "$1" "$2" > /dev/null; then
        return 0 # Success/Pass
    else
        echo "Expected:"
        cat "$2"
        echo "Got:"
        cat "$1"
        return 1 # Failure
    fi
}

# Function to check if program exits with expected status
check_exit_status() {
    EXPECTED=$1
    shift
    
    "$@"
    ACTUAL=$?
    
    if [ $ACTUAL -eq $EXPECTED ]; then
        return 0 # Success/Pass
    else
        echo "Expected exit status: $EXPECTED"
        echo "Actual exit status: $ACTUAL"
        return 1 # Failure
    fi
}

# Setup test environment
setup() {
    print_header "Setting up test environment"
    
    # Create test directory
    echo "Creating test directory..."
    mkdir -p pipex_test
    cd pipex_test
    
    # Create test files
    echo "Creating test files..."
    echo -e "hello world\nhello test\ngoodbye world\n1234 numbers\nHELLO uppercase" > infile
    
    # Create a large file for performance testing
    echo "Creating large test file..."
    for i in {1..1000}; do
        echo "Line $i with some random text hello world goodbye test" >> largefile
    done
    
    # Create a binary file
    echo "Creating binary file..."
    head -c 1024 /dev/urandom > binary_file
    
    # Create a read-only directory for permission tests
    echo "Creating read-only directory..."
    mkdir -p readonly
    touch readonly/placeholder
    chmod 444 readonly
    
    echo "Setup complete."
}

# Clean up test environment
cleanup() {
    print_header "Cleaning up test environment"
    
    echo "Removing test directory..."
    cd ..
    rm -rf pipex_test
    
    echo "Cleanup complete."
}

# Test functions
test_simple_pipe() {
    ../pipex infile "grep hello" "wc -l" outfile1
    < infile grep hello | wc -l > outfile1_expected
    compare_files outfile1 outfile1_expected
}

test_multiple_word_command() {
    ../pipex infile "grep -i hello" "wc -w" outfile2
    < infile grep -i hello | wc -w > outfile2_expected
    compare_files outfile2 outfile2_expected
}

test_commands_with_quotes() {
    ../pipex infile "grep \"world\"" "wc -l" outfile3
    < infile grep "world" | wc -l > outfile3_expected
    compare_files outfile3 outfile3_expected
}

test_path_based_commands() {
    ../pipex infile "/bin/grep hello" "/usr/bin/wc -l" outfile4
    < infile /bin/grep hello | /usr/bin/wc -l > outfile4_expected
    compare_files outfile4 outfile4_expected
}

test_nonexistent_input_file() {
    ../pipex nonexistentfile "cat" "wc -l" outfile5
    # Should create outfile but it will be empty (0 lines counted)
    if [ -f outfile5 ]; then
        cat /dev/null > outfile5_expected
        compare_files outfile5 outfile5_expected
    else
        echo "Failed: outfile5 was not created"
        return 1
    fi
}

test_nonexistent_command() {
    ../pipex infile "nonexistentcommand" "wc -l" outfile6
    # Should create outfile with 0 lines
    if [ -f outfile6 ]; then
        cat /dev/null > outfile6_expected
        compare_files outfile6 outfile6_expected
    else
        echo "Failed: outfile6 was not created"
        return 1
    fi
}

test_invalid_command_arguments() {
    ../pipex infile "ls --invalid-option" "wc -l" outfile7
    # The error message from ls goes to stderr, not through the pipe
    # So the output should be the wc -l of an empty input
    echo "0" > outfile7_expected
    compare_files outfile7 outfile7_expected
}

test_permission_denied_output() {
    ../pipex infile "cat" "wc -l" readonly/outfile8
    # This should fail with a permission error
    # Return 0 (pass) if the program exits with a non-zero status
    [ $? -ne 0 ] && return 0 || return 1
}

test_empty_input_file() {
    touch emptyfile
    ../pipex emptyfile "grep hello" "wc -l" outfile9
    echo "0" > outfile9_expected
    compare_files outfile9 outfile9_expected
}

test_large_output() {
    # Test with the large file we created earlier
    ../pipex largefile "grep Line" "wc -l" outfile10
    < largefile grep Line | wc -l > outfile10_expected
    compare_files outfile10 outfile10_expected
}

test_command_with_nonzero_exit() {
    ../pipex infile "grep nonexistentpattern" "wc -l" outfile11
    < infile grep nonexistentpattern | wc -l > outfile11_expected
    compare_files outfile11 outfile11_expected
}

test_special_characters() {
    ../pipex infile "grep '[0-9]'" "sort -r" outfile12
    < infile grep '[0-9]' | sort -r > outfile12_expected
    compare_files outfile12 outfile12_expected
}

test_memory_leaks() {
    # Only run if valgrind is installed
    if command -v valgrind &> /dev/null; then
        valgrind --leak-check=full --error-exitcode=1 ../pipex infile "cat" "wc -l" outfile13
        # If valgrind finds leaks, it will exit with non-zero status
        return $?
    else
        echo "Skipping memory leak test: valgrind not installed"
        return 0
    fi
}

test_fd_leaks() {
    # Run program multiple times
    for i in {1..5}; do
        ../pipex infile "cat" "wc -l" outfile14_$i
    done
    
    # Use lsof to check if any fd's are left open
    # This is a simple check and might need adjustment
    FD_COUNT_BEFORE=$(lsof -p $$ | wc -l)
    ../pipex infile "cat" "wc -l" outfile14_final
    FD_COUNT_AFTER=$(lsof -p $$ | wc -l)
    
    if [ $FD_COUNT_AFTER -le $((FD_COUNT_BEFORE + 1)) ]; then
        return 0
    else
        echo "Possible file descriptor leak detected"
        echo "FDs before: $FD_COUNT_BEFORE, FDs after: $FD_COUNT_AFTER"
        return 1
    fi
}

# Bonus features tests - these will be run only if specified
test_multiple_pipes() {
    ../pipex infile "grep hello" "sort" "uniq" "wc -l" outfile15
    < infile grep hello | sort | uniq | wc -l > outfile15_expected
    compare_files outfile15 outfile15_expected
}

test_here_doc() {
    # Create a heredoc input file for comparison
    cat > heredoc_test << 'EOF'
line 1 hello
line 2 test
line 3 hello again
EOF

    # Test heredoc feature
    echo -e "line 1 hello\nline 2 test\nline 3 hello again\nLIMITER" | ../pipex here_doc LIMITER "grep hello" "wc -l" outfile16
    < heredoc_test grep hello | wc -l > outfile16_expected
    compare_files outfile16 outfile16_expected
}

# Main function to run all tests
main() {
    # Check if pipex executable exists
    if [ ! -f "../pipex" ]; then
        echo -e "${RED}Error: pipex executable not found in parent directory${NC}"
        echo "Make sure to compile your program before running tests"
        exit 1
    fi
    
    # Setup test environment
    setup
    
    # Basic Functionality Tests
    print_header "Basic Functionality Tests"
    run_test "Simple Command Pipe" test_simple_pipe
    run_test "Multiple Word Command" test_multiple_word_command
    run_test "Commands with Quotes" test_commands_with_quotes
    run_test "Path-Based Commands" test_path_based_commands
    
    # Error Handling Tests
    print_header "Error Handling Tests"
    run_test "Non-existent Input File" test_nonexistent_input_file
    run_test "Non-existent Command" test_nonexistent_command
    run_test "Invalid Command Arguments" test_invalid_command_arguments
    run_test "Permission Denied on Output File" test_permission_denied_output
    
    # Edge Cases
    print_header "Edge Cases"
    run_test "Empty Input File" test_empty_input_file
    run_test "Large Output" test_large_output
    run_test "Command with Non-Zero Exit Status" test_command_with_nonzero_exit
    run_test "Special Characters in Commands" test_special_characters
    
    # Memory Management Tests
    print_header "Memory Management Tests"
    run_test "Memory Leaks" test_memory_leaks
    run_test "File Descriptor Leaks" test_fd_leaks
    
    # Bonus Features Tests (if specified)
    if [ "$1" = "--bonus" ]; then
        print_header "Bonus Features Tests"
        run_test "Multiple Pipes" test_multiple_pipes
        run_test "Here Document" test_here_doc
    fi
    
    # Cleanup
    cleanup
    
    # Summary
    print_header "Test Summary"
    echo -e "Total tests run: ${TOTAL}"
    echo -e "${GREEN}Tests passed: ${PASSED}${NC}"
    echo -e "${RED}Tests failed: ${FAILED}${NC}"
    
    # Return overall status
    if [ $FAILED -eq 0 ]; then
        echo -e "\n${GREEN}All tests passed!${NC}"
        exit 0
    else
        echo -e "\n${RED}Some tests failed!${NC}"
        exit 1
    fi
}

# Run main function with all arguments passed to the script
main "$@"
