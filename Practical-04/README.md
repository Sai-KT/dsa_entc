# Practical 04: Decimal to Binary Conversion using Stack (LIFO)

## 1. Practical Number
Practical 04

## 2. Practical Title / Aim
Implement the Stack Abstract Data Type (ADT) using an array in C and apply its Last-In-First-Out (LIFO) property to convert a decimal integer into its binary equivalent.

## 3. Objective
- Understand the concept and mechanics of the Stack data structure.
- Implement primary stack operations: `push`, `pop`, `isEmpty`, and `isFull`.
- Demonstrate the application of Stack's LIFO property in reversing remainders during number base conversions.
- Analyze the time and space complexity of stack-based algorithms.

## 4. Algorithm / Logic Used

### A. Number Base Conversion Algorithm
1. **Start**
2. Input decimal integer $N$.
3. If $N = 0$, output binary `0` and terminate.
4. Initialize an empty stack `S`.
5. While $N > 0$:
   1. Compute remainder $R = N \pmod 2$.
   2. Push $R$ onto stack `S`.
   3. Update $N = \lfloor N / 2 \rfloor$.
6. While stack `S` is not empty:
   1. Pop top element from `S`.
   2. Print the popped digit.
7. **End**

## 5. Code Implementation
Source code: [practical-04.c](practical-04.c)

```c
void decimalToBinary(int decimal) {
    Stack s;
    initStack(&s);

    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    int temp = decimal;
    while (temp > 0) {
        push(&s, temp % 2);
        temp /= 2;
    }

    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}
```

## 6. Complexity Analysis
- **Time Complexity:**
  - Number of divisions by 2 for value $N$ is $\lfloor \log_2 N \rfloor + 1$.
  - Each `push` and `pop` operation executes in $O(1)$ constant time.
  - **Best Case ($N=0$ or $1$):** $O(1)$
  - **Average Case:** $O(\log_2 N)$
  - **Worst Case:** $O(\log_2 N)$
- **Space Complexity:**
  - **Auxiliary Space:** $O(\log_2 N)$ stack elements stored simultaneously to hold binary digits.

## 7. Input / Output & Test Cases

### Test Case 1: Standard Decimal Number ($N = 13$)
**Input:**
```text
Enter a non-negative decimal number: 13
```
**Output:**
```text
Binary equivalent of 13 is: 1101
```

### Test Case 2: Zero Input ($N = 0$)
**Input:**
```text
Enter a non-negative decimal number: 0
```
**Output:**
```text
Binary equivalent: 0
```

### Test Case 3: Power of Two ($N = 64$)
**Input:**
```text
Enter a non-negative decimal number: 64
```
**Output:**
```text
Binary equivalent of 64 is: 1000000
```

### Test Case 4: Invalid Input Validation ($N < 0$)
**Input:**
```text
Enter a non-negative decimal number: -5
```
**Output:**
```text
Error: Please enter a valid non-negative integer (>= 0).
```

## 8. Conclusion
Successfully implemented the Stack ADT with array-based storage and applied the LIFO mechanism to reverse remainder sequences in decimal-to-binary radix conversion. Verified that the time and auxiliary space complexities are bounded logarithmically by $O(\log_2 N)$.
