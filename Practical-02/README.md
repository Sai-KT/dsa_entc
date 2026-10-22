# Practical 02: Student Database Management System

## 1. Practical Number
Practical 02

## 2. Practical Title / Aim
Design and implement a menu-driven Student Database Management System in C using an array of structures to create, display, and search student academic records.

## 3. Objective
- Understand data representation using user-defined structures (`struct`) in C.
- Manage collections of records using an array of structures.
- Implement modular functions for database operations: record creation, formatted tabular display, and linear search.
- Evaluate the computational complexity of sequential search operations.

## 4. Algorithm / Logic Used

### A. Record Creation (`createStudents`)
1. **Start**
2. For each student $i$ from $0$ to $n-1$:
   1. Read `roll_no`, `name`, `program`, `sub1_name`, `sub1_marks`, `sub2_name`, `sub2_marks`.
   2. Compute `total_marks = sub1_marks + sub2_marks`.
   3. Compute `average = total_marks / 2.0`.
3. Increment global student count.
4. **End**

### B. Linear Search by Roll Number (`searchStudent`)
1. **Start**
2. Input target `search_key` (roll number).
3. Set `found = 0`.
4. Traverse array from index `0` to `n-1`:
   - If `database[i].roll_no == search_key`:
     - Display all details for student $i$.
     - Set `found = 1` and break loop.
5. If `found == 0`, display "Student NOT FOUND".
6. **End**

## 5. Code Implementation
Source code: [practical-02.c](practical-02.c)

```c
typedef struct Student {
    int roll_no;
    char name[50];
    char program[30];
    char sub1_name[20];
    char sub2_name[20];
    int sub1_marks;
    int sub2_marks;
    int total_marks;
    float average;
} Student;
```

## 6. Complexity Analysis

### Time Complexity:
- **Record Creation:** $O(n)$ where $n$ is the number of records being added.
- **Display Operation:** $O(n)$ to traverse and print all records.
- **Search Operation (Linear Search):**
  - **Best Case:** $\Omega(1)$ (target student is the first record).
  - **Average Case:** $\Theta(n)$ (target is midway in the array).
  - **Worst Case:** $O(n)$ (target is at the end or not present).

### Space Complexity:
- **Auxiliary Space:** $O(1)$ runtime auxiliary memory.
- **Data Structure Space:** $O(N)$ where $N$ is maximum capacity of the array (`MAX_STUDENTS`).

## 7. Input / Output & Test Cases

### Test Case 1: Record Creation & Tabular Display
**Input:**
```text
Option: 1 (Create)
Count: 2
Student 1: 101, Alice, SE_Computer, DSA, 85, OOP, 90
Student 2: 102, Bob, SE_Computer, DSA, 78, OOP, 82
Option: 2 (Display)
```
**Output:**
```text
========================================================================================
Roll No  Name             Program         Sub1       Marks    Sub2       Marks    Total    Average 
========================================================================================
101      Alice            SE_Computer     DSA        85       OOP        90       175      87.50   
102      Bob              SE_Computer     DSA        78       OOP        82       160      80.00   
========================================================================================
```

### Test Case 2: Successful Search by Roll Number
**Input:**
```text
Option: 3 (Search)
Enter Roll Number to search: 101
```
**Output:**
```text
--- STUDENT RECORD FOUND ---
Roll Number : 101
Name        : Alice
Program     : SE_Computer
DSA Marks   : 85
OOP Marks   : 90
Total Marks : 175
Average     : 87.50
```

### Test Case 3: Search for Non-Existent Record
**Input:**
```text
Option: 3 (Search)
Enter Roll Number to search: 999
```
**Output:**
```text
Student with Roll Number 999 NOT FOUND.
```

## 8. Conclusion
Successfully implemented an in-memory Student Database Management System using an array of structures in C. Demonstrated structured record management, formatted reporting, and evaluated the linear search algorithm operating in $O(n)$ time complexity.
