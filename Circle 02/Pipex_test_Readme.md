# Test Cases for the Pipex Project (42)

Pipex is a project where you implement Unix pipe functionality in C. Below is a comprehensive set of test cases to validate your implementation thoroughly.

## Basic Functionality Tests

These test cases verify that your program correctly mimics the shell command: `< infile cmd1 | cmd2 > outfile`

### Test 1: Simple Command Pipe
```bash
# Your program
./pipex infile "grep hello" "wc -l" outfile

# Equivalent shell command
< infile grep hello | wc -l > outfile_expected

# Validation
diff outfile outfile_expected
```

### Test 2: Multiple Word Command
```bash
./pipex infile "grep -i hello" "wc -w" outfile

# Equivalent
< infile grep -i hello | wc -w > outfile_expected
```

### Test 3: Commands with Quotes
```bash
./pipex infile "grep \"hello world\"" "wc -l" outfile

# Equivalent
< infile grep "hello world" | wc -l > outfile_expected
```

### Test 4: Path-Based Commands
Test that your program uses PATH environment variable correctly:
```bash
./pipex infile "/bin/grep hello" "/usr/bin/wc -l" outfile

# Equivalent
< infile /bin/grep hello | /usr/bin/wc -l > outfile_expected
```

## Error Handling Tests

### Test 5: Non-existent Input File
```bash
./pipex nonexistentfile "cat" "wc -l" outfile
```
Expected behavior: Error message about input file not found, but should still create outfile with output from the second command (which will receive no input).

### Test 6: Non-existent Command
```bash
./pipex infile "nonexistentcommand" "wc -l" outfile
```
Expected behavior: Error message about command not found, but should continue with the second command execution.

### Test 7: Invalid Command Arguments
```bash
./pipex infile "ls --invalid-option" "wc -l" outfile
```
Expected behavior: First command should fail, but the second command should still be executed.

### Test 8: Permission Denied on Output File
Create a read-only directory and try to output there:
```bash
mkdir -p readonly && chmod 444 readonly
./pipex infile "cat" "wc -l" readonly/outfile
```
Expected behavior: Error message about permission denied for output file.

## Edge Cases

### Test 9: Empty Input File
```bash
touch emptyfile
./pipex emptyfile "grep hello" "wc -l" outfile
```
Expected output: `0` (assuming wc -l returns 0 for empty input)

### Test 10: Commands That Generate Large Output
```bash
./pipex infile "yes hello | head -n 100000" "wc -l" outfile
```
Tests handling of large data between pipes.

### Test 11: Commands That Fail with Non-Zero Exit Status
```bash
./pipex infile "grep nonexistentpattern" "wc -l" outfile
```
Expected behavior: First command exits with status 1, but the pipe should still work correctly.

### Test 12: Special Characters in Commands
```bash
./pipex infile "grep '[0-9]'" "sort -r" outfile
```
Tests handling of special characters in command arguments.

## Memory Management Tests

### Test 13: Memory Leaks
Run your program with valgrind to check for memory leaks:
```bash
valgrind --leak-check=full ./pipex infile "cat" "wc -l" outfile
```
Expected behavior: No memory leaks reported.

### Test 14: File Descriptor Leaks
Run your program multiple times in succession and check if any file descriptors are left open:
```bash
for i in {1..10}; do ./pipex infile "cat" "wc -l" outfile; done
lsof -p $$ | grep -v COMMAND | wc -l
```
The number of open file descriptors should remain constant.

## Bonus Features Tests (if applicable)

### Test 15: Multiple Pipes (Bonus)
If your pipex supports multiple pipes:
```bash
./pipex infile "grep hello" "sort" "uniq" "wc -l" outfile

# Equivalent
< infile grep hello | sort | uniq | wc -l > outfile_expected
```

### Test 16: Here Document (Bonus)
If your pipex supports here_doc:
```bash
./pipex here_doc LIMITER "grep hello" "wc -l" outfile
# Then input text, ending with LIMITER

# Equivalent
cat << LIMITER | grep hello | wc -l > outfile_expected
# Same input text
LIMITER
```

## Automated Testing Script

Here's a shell script you can use to automate these tests:

```bash
#!/bin/bash

echo "==== Testing pipex functionality ===="

# Setup
mkdir -p test_dir
cd test_dir
echo "hello world\nhello test\ngoodbye world" > infile
echo "binary data" > binary_file

# Test 1: Simple Command Pipe
../pipex infile "grep hello" "wc -l" outfile1
< infile grep hello | wc -l > outfile1_expected
if diff outfile1 outfile1_expected > /dev/null; then
    echo "Test 1: PASSED"
else
    echo "Test 1: FAILED"
    echo "Expected:"
    cat outfile1_expected
    echo "Got:"
    cat outfile1
fi

# Continue with other tests...
```

## Tips for Testing

1. **Methodical Approach**: Start with simple test cases and gradually move to more complex ones.

2. **Compare with Shell**: Always compare your program's output with the equivalent shell command.

3. **Error Codes**: Check that your program returns the appropriate exit codes, especially for error conditions.

4. **Memory Tools**: Use tools like Valgrind and AddressSanitizer to check for memory issues.

5. **Edge Cases**: Pay special attention to edge cases like empty files, large outputs, and special characters.

Would you like me to elaborate on any specific test case or provide additional tests for any particular aspect of the project?
