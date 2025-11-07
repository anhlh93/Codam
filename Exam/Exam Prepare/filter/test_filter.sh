#!/bin/bash

# Filter Program Automated Test Script
# Usage: ./test_filter.sh [path_to_filter_program]
# If no path provided, assumes ./filter exists in current directory

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Filter program path
FILTER_PROG="${1:-./filter}"

# Function to print colored output
print_color() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${NC}"
}

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local pattern="$3"
    local expected="$4"
    local test_type="${5:-normal}"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    print_color $BLUE "Test $TOTAL_TESTS: $test_name"
    
    # Special handling for different input types
    local result
    case "$test_type" in
        "printf")
            result=$(printf "$input" | $FILTER_PROG "$pattern" 2>&1)
            ;;
        "echo_n")
            result=$(echo -n "$input" | $FILTER_PROG "$pattern" 2>&1)
            ;;
        *)
            result=$(echo "$input" | $FILTER_PROG "$pattern" 2>&1)
            ;;
    esac
    
    if [ "$result" = "$expected" ]; then
        print_color $GREEN "  ✓ PASS"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_color $RED "  ✗ FAIL"
        echo "    Expected: '$expected'"
        echo "    Got:      '$result'"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    echo
}

# Function to run error test (expects non-zero exit code)
run_error_test() {
    local test_name="$1"
    local command="$2"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    print_color $BLUE "Test $TOTAL_TESTS: $test_name"
    
    eval "$command" >/dev/null 2>&1
    local exit_code=$?
    
    if [ $exit_code -ne 0 ]; then
        print_color $GREEN "  ✓ PASS (correctly returned non-zero exit code: $exit_code)"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_color $RED "  ✗ FAIL (should have returned non-zero exit code)"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    echo
}

# Function to run sed comparison test
run_sed_test() {
    local test_name="$1"
    local input="$2"
    local pattern="$3"
    local test_type="${4:-normal}"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    print_color $BLUE "Test $TOTAL_TESTS: $test_name (sed comparison)"
    
    # Create temporary files
    local filter_output="/tmp/filter_test_$$"
    local sed_output="/tmp/sed_test_$$"
    
    # Get expected output from sed
    local sed_pattern=$(printf "%*s" ${#pattern} | tr ' ' '*')
    
    # Run both commands
    case "$test_type" in
        "printf")
            printf "$input" | $FILTER_PROG "$pattern" > "$filter_output" 2>/dev/null
            printf "$input" | sed "s/$pattern/$sed_pattern/g" > "$sed_output" 2>/dev/null
            ;;
        "echo_n")
            echo -n "$input" | $FILTER_PROG "$pattern" > "$filter_output" 2>/dev/null
            echo -n "$input" | sed "s/$pattern/$sed_pattern/g" > "$sed_output" 2>/dev/null
            ;;
        *)
            echo "$input" | $FILTER_PROG "$pattern" > "$filter_output" 2>/dev/null
            echo "$input" | sed "s/$pattern/$sed_pattern/g" > "$sed_output" 2>/dev/null
            ;;
    esac
    
    if diff -q "$filter_output" "$sed_output" >/dev/null; then
        print_color $GREEN "  ✓ PASS (matches sed output)"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_color $RED "  ✗ FAIL (differs from sed output)"
        echo "    Filter output:"
        cat "$filter_output" | head -3
        echo "    Sed output:"
        cat "$sed_output" | head -3
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    
    # Cleanup
    rm -f "$filter_output" "$sed_output"
    echo
}

# Function to check if filter program exists
check_filter_program() {
    if [ ! -f "$FILTER_PROG" ]; then
        print_color $RED "Error: Filter program not found at '$FILTER_PROG'"
        print_color $YELLOW "Please compile your filter program or specify the correct path:"
        print_color $YELLOW "  Usage: $0 [path_to_filter_program]"
        exit 1
    fi
    
    if [ ! -x "$FILTER_PROG" ]; then
        print_color $RED "Error: Filter program '$FILTER_PROG' is not executable"
        print_color $YELLOW "Try: chmod +x $FILTER_PROG"
        exit 1
    fi
}

# Function to print test summary
print_summary() {
    echo "=================================="
    print_color $BLUE "TEST SUMMARY"
    echo "=================================="
    echo "Total tests run: $TOTAL_TESTS"
    print_color $GREEN "Passed: $PASSED_TESTS"
    print_color $RED "Failed: $FAILED_TESTS"
    
    if [ $FAILED_TESTS -eq 0 ]; then
        print_color $GREEN "🎉 All tests passed!"
        exit 0
    else
        local pass_rate=$(( (PASSED_TESTS * 100) / TOTAL_TESTS ))
        print_color $YELLOW "Pass rate: ${pass_rate}%"
        exit 1
    fi
}

# Main test execution
main() {
    print_color $YELLOW "🧪 Starting Filter Program Test Suite"
    print_color $BLUE "Using filter program: $FILTER_PROG"
    echo
    
    check_filter_program
    
    # Basic Functionality Tests
    print_color $YELLOW "=== Basic Functionality Tests ==="
    
    run_test "Basic replacement (given example)" \
        "abcdefaaaabcdeabcabcdabc" \
        "abc" \
        "***defaaa***de******d***"
    
    run_test "Overlapping pattern (given example)" \
        "ababcabababc" \
        "ababc" \
        "*****ab*****"
    
    run_test "Single character replacement" \
        "hello world" \
        "l" \
        "he**o wor*d"
    
    run_test "No matches" \
        "hello world" \
        "xyz" \
        "hello world"
    
    run_test "Entire string is the pattern" \
        "test" \
        "test" \
        "****"
    
    # Edge Cases
    print_color $YELLOW "=== Edge Case Tests ==="
    
    run_test "Empty input" \
        "" \
        "abc" \
        "" \
        "echo_n"
    
    run_test "Single character input" \
        "a" \
        "a" \
        "*" \
        "echo_n"
    
    run_test "Pattern longer than input" \
        "ab" \
        "abcd" \
        "ab"
    
    run_test "Repeated pattern" \
        "abababab" \
        "ab" \
        "********"
    
    run_test "Pattern at the beginning" \
        "abcdefgh" \
        "abc" \
        "***defgh"
    
    run_test "Pattern at the end" \
        "defghabc" \
        "abc" \
        "defgh***"
    
    run_test "Pattern in the middle" \
        "defabcghi" \
        "abc" \
        "def***ghi"
    
    # Multi-line Input Tests
    print_color $YELLOW "=== Multi-line Input Tests ==="
    
    run_test "Multi-line input with newlines" \
        "abc\ndef\nabc" \
        "abc" \
        "***\ndef\n***" \
        "printf"
    
    run_test "Pattern spanning across newlines" \
        "ab\nc" \
        "abc" \
        "ab\nc" \
        "printf"
    
    # Special Characters
    print_color $YELLOW "=== Special Character Tests ==="
    
    run_test "Pattern with spaces" \
        "hello world test" \
        " " \
        "hello*world*test"
    
    run_test "Pattern with special characters" \
        "test@#\$test" \
        "@#\$" \
        "test***test"
    
    run_test "Pattern with tabs" \
        "hello\tworld\ttest" \
        "\t" \
        "hello*world*test" \
        "printf"
    
    # Error Handling Tests
    print_color $YELLOW "=== Error Handling Tests ==="
    
    run_error_test "No arguments" \
        "echo 'test' | $FILTER_PROG"
    
    run_test "Empty string argument" \
        "test" \
        "" \
        "test"
    
    # Sed Comparison Tests
    print_color $YELLOW "=== Sed Comparison Tests ==="
    
    run_sed_test "Compare with sed - basic case" \
        "hello world hello" \
        "hello"
    
    run_sed_test "Compare with sed - complex case" \
        "ababcdefababcghi" \
        "ababc"
    
    run_sed_test "Compare with sed - single char" \
        "aaaaaa" \
        "a"
    
    # Performance Tests (simplified)
    print_color $YELLOW "=== Performance Tests ==="
    
    # Generate large input for performance test
    local large_input=$(python3 -c "print('abc' * 100 + 'def' + 'abc' * 100)" 2>/dev/null || echo "abcabcabcdef")
    run_test "Large input test" \
        "$large_input" \
        "abc" \
        "$(echo "$large_input" | sed 's/abc/***/g')"
    
    # Long pattern test
    run_test "Long pattern test" \
        "this is a very long pattern test very long pattern end" \
        "very long pattern" \
        "this is a ***************** test ***************** end"
    
    # Print final summary
    print_summary
}

# Handle script interruption
trap 'print_color $RED "\n🚫 Tests interrupted!"; exit 130' INT TERM

# Run main function with all arguments
main "$@"