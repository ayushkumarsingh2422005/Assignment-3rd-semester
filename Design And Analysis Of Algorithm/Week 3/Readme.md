# Time Complexity of Programs

This repository contains various C programs, along with their corresponding time complexities.

## Programs and Their Time Complexities

### Factorial Program
- **Language:** C
- **Time Complexity:** `O(n)`
- **Description:** This program computes the factorial of a given number. The time complexity is linear because the program iterates through each number from 1 to `n` to calculate the factorial.

### Binary Search Program
- **Language:** C
- **Time Complexity:** `O(log(n))`
- **Description:** This program performs a binary search on a sorted array. The time complexity is logarithmic because the search space is halved with each iteration.

### Tower of Hanoi Program
- **Language:** C
- **Time Complexity:** `O(2^n)`
- **Description:** This program solves the Tower of Hanoi problem using recursion. The time complexity is exponential due to the recursive nature of the problem, where each move involves solving a smaller instance of the problem.

## How to Run the Programs

1. Clone the repository.
2. Navigate to the directory containing the desired program.
3. Compile the C file using a C compiler:
   ```sh
   gcc program_name.c -o program_name
