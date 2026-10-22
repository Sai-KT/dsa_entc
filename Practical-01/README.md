# Practical 01: Right-Angled Number Pattern Generation

## 1. Practical Number
Practical 01

## 2. Practical Title / Aim
Write a program in C to generate and display a right-angled numeric triangle pattern for $n$ rows using nested looping structures.

## 3. Objective
- Understand nested loop execution flow in C.
- Implement iteration-based pattern printing with dynamic user input.
- Analyze the time and space complexity of nested looping structures.

## 4. Algorithm / Logic Used
1. **Start**
2. Prompt user to enter the number of rows $n$.
3. Validate that $n > 0$. If invalid, print an error message and terminate.
4. Outer loop: Initialize row counter `i = 1`. Repeat while `i <= n`:
   1. Inner loop: Initialize column counter `j = 1`. Repeat while `j <= i`:
      1. Print the value of `j` followed by a space.
      2. Increment `j` by 1.
   2. Print a newline character `\n` to advance to the next line.
   3. Increment `i` by 1.
5. **End**

## 5. Code Implementation
Source code: [practical-01.c](practical-01.c)

```c
void printNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}
```

## 6. Complexity Analysis
- **Time Complexity:**
  - Total number of inner loop executions: $\sum_{i=1}^{n} i = \frac{n(n+1)}{2} = \frac{n^2 + n}{2}$
  - **Best Case:** $\Omega(n^2)$
  - **Average Case:** $\Theta(n^2)$
  - **Worst Case:** $O(n^2)$
- **Space Complexity:**
  - **Auxiliary Space:** $O(1)$ (only loop counters `i`, `j` and input `n` are stored in memory).

## 7. Input / Output & Test Cases

### Test Case 1: Standard Execution ($n = 4$)
**Input:**
```text
Enter number of rows (n): 4
```
**Output:**
```text
Generated Pattern:
1 
1 2 
1 2 3 
1 2 3 4 
```

### Test Case 2: Boundary Execution ($n = 1$)
**Input:**
```text
Enter number of rows (n): 1
```
**Output:**
```text
Generated Pattern:
1 
```

### Test Case 3: Invalid Input Validation ($n \le 0$)
**Input:**
```text
Enter number of rows (n): -3
```
**Output:**
```text
Error: Please enter a positive integer greater than 0.
```

## 8. Conclusion
Successfully implemented the right-angled number pattern generation using nested `for` loops in C. Verified that the execution time scales quadratically as $O(n^2)$ with minimal $O(1)$ auxiliary memory requirement.
