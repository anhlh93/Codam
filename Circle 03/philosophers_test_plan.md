# Philosophers Project Test Plan

## Overview
This is a comprehensive test plan for evaluating the Philosophers project (Dining Philosophers Problem) implementation.

## Project Requirements Recap
- **Mandatory**: Threading with mutexes (`philo/`)
- **Bonus**: Processes with semaphores (`philo_bonus/`)
- **Arguments**: `number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`

---

## 1. Basic Compilation & Setup Tests

### 1.1 Directory Structure
```bash
# Check mandatory part
ls -la philo/
# Should contain: Makefile, *.h, *.c files

# Check bonus part (if implemented)
ls -la philo_bonus/
# Should contain: Makefile, *.h, *.c files
```

### 1.2 Makefile Tests
```bash
cd philo/

# Test compilation
make
# Should create 'philo' executable

# Test cleaning
make clean    # Should remove object files
make fclean   # Should remove executable and objects
make re       # Should recompile everything

# Check required rules exist
make all
make NAME     # Should work if NAME is defined
```

### 1.3 Norm Check
```bash
# If using 42 Norm (adjust command as needed)
norminette philo/
# Should return no errors
```

---

## 2. Argument Validation Tests

### 2.1 Valid Arguments
```bash
./philo 4 410 200 200        # Basic test
./philo 5 800 200 200        # 5 philosophers
./philo 4 410 200 200 7      # With optional eat count
./philo 1 800 200 200        # Edge case: 1 philosopher
```

### 2.2 Invalid Arguments
```bash
./philo                      # No arguments
./philo 4                    # Too few arguments
./philo 4 410 200           # Missing time_to_sleep
./philo 0 410 200 200        # Zero philosophers
./philo -1 410 200 200       # Negative philosophers
./philo 4 0 200 200          # Zero time_to_die
./philo 4 410 -1 200         # Negative time_to_eat
./philo abc 410 200 200      # Non-numeric arguments
./philo 4 410 200 200 0      # Zero eat count
./philo 4 410 200 200 -1     # Negative eat count
```

**Expected**: Program should handle invalid inputs gracefully (error message + exit)

---

## 3. Core Functionality Tests

### 3.1 Basic Simulation Tests

#### Test 1: No Death Scenario
```bash
./philo 4 410 200 200
# Expected: 
# - Philosophers should eat, sleep, think continuously
# - No philosopher should die
# - Simulation should run indefinitely
# - Log format: timestamp_in_ms X has taken a fork
#              timestamp_in_ms X is eating
#              timestamp_in_ms X is sleeping  
#              timestamp_in_ms X is thinking
```

#### Test 2: Death Scenario
```bash
./philo 4 310 200 100
# Expected:
# - One philosopher should die around 310ms after last meal
# - Death message: timestamp_in_ms X died
# - Death should be detected within 10ms of actual time
# - Simulation should stop after death
```

#### Test 3: Limited Eating
```bash
./philo 4 410 200 200 7
# Expected:
# - Simulation stops when all philosophers eat 7 times
# - No deaths should occur
# - Each philosopher eats exactly 7 times
```

### 3.2 Edge Cases

#### Test 4: Single Philosopher
```bash
./philo 1 800 200 200
# Expected:
# - Philosopher has only one fork
# - Should die because can't eat (needs 2 forks)
# - Death should occur around 800ms
```

#### Test 5: Two Philosophers
```bash
./philo 2 410 200 200
# Expected:
# - Should work without deadlock
# - Both should be able to eat alternately
```

#### Test 6: Many Philosophers
```bash
./philo 200 410 200 200
# Expected:
# - Should handle large numbers without issues
# - No crashes or memory issues
# - All philosophers should be able to eat eventually
```

---

## 4. Timing & Precision Tests

### 4.1 Death Detection Precision
```bash
./philo 1 800 400 400
# Monitor timestamp differences:
# - Last eating timestamp
# - Death announcement timestamp
# - Difference should be close to 800ms
# - Death announcement within 10ms of actual death
```

### 4.2 Eating Duration
```bash
./philo 4 410 200 200
# Verify:
# - Time between "X is eating" and next state is ~200ms
# - Sleeping duration is ~200ms
```

### 4.3 Stress Timing
```bash
./philo 4 800 200 200
./philo 5 600 150 150  
./philo 3 500 100 100
# Test various timing combinations
```

---

## 5. Concurrency & Race Condition Tests

### 5.1 Output Consistency
```bash
./philo 4 410 200 200
# Check output for:
# - No overlapping messages
# - Clean, readable format
# - Proper timestamps in milliseconds
# - Correct philosopher numbering (1 to N)
```

### 5.2 Data Race Detection
```bash
# If available, use thread sanitizer
gcc -fsanitize=thread -g philo/*.c -lpthread -o philo_debug
./philo_debug 4 410 200 200

# Or use valgrind with helgrind
valgrind --tool=helgrind ./philo 4 410 200 200
```

### 5.3 Memory Issues
```bash
valgrind --leak-check=full ./philo 4 410 200 200
valgrind --leak-check=full ./philo 1 800 200 200
# Should show no memory leaks
```

---

## 6. Stress & Performance Tests

### 6.1 Long Running Tests
```bash
./philo 4 410 200 200 1000
# Should complete without issues

./philo 50 800 200 200 10
# Many philosophers, limited eating
```

### 6.2 Quick Death Tests
```bash
./philo 4 1 200 200      # Very quick death
./philo 4 100 50 50      # Fast eating cycles
```

### 6.3 Resource Limits
```bash
./philo 1000 1000 200 200 1  # Many philosophers
# Check system limits and performance
```

---

## 7. Bonus Part Tests (if implemented)

### 7.1 Compilation
```bash
cd philo_bonus/
make
# Should create 'philo_bonus' executable
```

### 7.2 Same Functional Tests
Run all the same tests as mandatory part but with `./philo_bonus`

### 7.3 Process-Specific Tests
```bash
# Check process creation
ps aux | grep philo_bonus
# Should show multiple processes when running

# Check semaphore usage
# Monitor system semaphores if tools available
```

---

## 8. Code Quality Checks

### 8.1 Forbidden Functions
Check source code doesn't use:
- Global variables
- Forbidden functions (only allowed ones listed in subject)

### 8.2 Implementation Requirements
**Mandatory Part:**
- Each philosopher = separate thread
- One fork between each pair of philosophers  
- Fork state protected by mutex

**Bonus Part:**
- Each philosopher = separate process
- Forks represented by semaphore
- Main process doesn't act as philosopher

---

## 9. Common Issues to Test For

### 9.1 Deadlock Detection
```bash
./philo 4 410 200 200
# Let run for several minutes
# Should not freeze/deadlock
```

### 9.2 Philosopher Starvation
```bash
./philo 5 800 200 200
# Monitor if any philosopher gets "stuck"
# All should eat regularly
```

### 9.3 Incorrect Death Timing
```bash
./philo 1 500 200 200
# Death should be at ~500ms, not 700ms (500+200)
```

### 9.4 Fork Management
- Philosophers should pick up both forks before eating
- Forks should be released after eating
- No fork duplication

---

## 10. Evaluation Criteria Checklist

### Mandatory Requirements
- [ ] Compiles without errors/warnings
- [ ] Makefile has all required rules
- [ ] Follows 42 Norm (if applicable)
- [ ] No memory leaks
- [ ] No data races
- [ ] Proper argument validation
- [ ] Correct output format
- [ ] Death detection within 10ms
- [ ] No overlapping messages
- [ ] Handles edge cases (1 philosopher, etc.)
- [ ] Works with optional 5th argument
- [ ] Philosophers don't die when they shouldn't
- [ ] Simulation stops appropriately

### Bonus Requirements (only if mandatory is perfect)
- [ ] All mandatory requirements pass
- [ ] Uses processes instead of threads
- [ ] Uses semaphores instead of mutexes
- [ ] Main process doesn't act as philosopher
- [ ] Identical functionality to mandatory part

---

## 11. Test Scripts

You can create automated test scripts:

```bash
#!/bin/bash
# Basic functionality test
echo "Testing basic functionality..."
timeout 10s ./philo 4 410 200 200 5

echo "Testing death scenario..."
timeout 5s ./philo 1 800 200 200

echo "Testing invalid arguments..."
./philo 0 410 200 200
./philo abc 410 200 200
```

Remember: The goal is to verify the implementation correctly simulates the dining philosophers problem while meeting all technical requirements.
