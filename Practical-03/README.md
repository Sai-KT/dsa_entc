# Practical 03: Contact Directory Searching (Linear vs Binary Search)

## 1. Practical Number
Practical 03

## 2. Practical Title / Aim
Implement a Contact Directory in C and evaluate search performance by comparing Linear Search with Binary Search using Bubble Sort, logging the number of comparisons made by each algorithm.

## 3. Objective
- Implement structure-based record storage for contacts.
- Perform sequential lookup using Linear Search on unsorted data.
- Implement Bubble Sort to arrange contacts lexicographically by name.
- Perform divide-and-conquer lookup using Binary Search on sorted data.
- Empirically compare the efficiency and comparison counts of both searching techniques.

## 4. Algorithm / Logic Used

### A. Linear Search (`linearSearch`)
1. **Start**
2. Initialize `comparisons = 0`.
3. Loop `i` from `0` to `n - 1`:
   - Increment `comparisons`.
   - If `c[i].name == key` (case-insensitive):
     - Return index `i`.
4. If loop completes, return `-1`.
5. **End**

### B. Bubble Sort (`bubbleSortContacts`)
1. For pass `i` from `0` to `n - 2`:
   - For `j` from `0` to `n - i - 2`:
     - If `c[j].name > c[j + 1].name`, swap `c[j]` and `c[j + 1]`.

### C. Binary Search (`binarySearch`)
1. **Start**
2. Initialize `low = 0`, `high = n - 1`, `comparisons = 0`.
3. While `low <= high`:
   - Increment `comparisons`.
   - Calculate `mid = low + (high - low) / 2`.
   - Compare `key` with `c[mid].name`:
     - If match: return `mid`.
     - If `key < c[mid].name`: set `high = mid - 1`.
     - Else: set `low = mid + 1`.
4. Return `-1` if not found.
5. **End**

## 5. Code Implementation
Source code: [practical-03.c](practical-03.c)

```c
int binarySearch(const Contact c[], int n, const char *key, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        int cmp = strcasecmp(key, c[mid].name);
        if (cmp == 0) return mid;
        else if (cmp < 0) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
```

## 6. Complexity Analysis

| Algorithm | Best Case Time | Average Case Time | Worst Case Time | Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **Linear Search** | $\Omega(1)$ | $\Theta(n)$ | $O(n)$ | $O(1)$ |
| **Bubble Sort** | $\Omega(n)$ | $\Theta(n^2)$ | $O(n^2)$ | $O(1)$ |
| **Binary Search** | $\Omega(1)$ | $\Theta(\log n)$ | $O(\log n)$ | $O(1)$ |

- **Comparison:** For $n = 1000$, Linear Search takes up to 1000 comparisons, whereas Binary Search takes at most $\lceil \log_2(1000) \rceil = 10$ comparisons.

## 7. Input / Output & Test Cases

### Test Case 1: Search Existing Contact
**Input:**
```text
Enter number of contacts: 3
Contact 1: Charlie, 9876543210, City_A
Contact 2: Alice, 9812345678, City_B
Contact 3: Bob, 9765432109, City_C
Search Target: Bob
```

**Output:**
```text
1. LINEAR SEARCH EXECUTION
Status     : Contact Found!
Name       : Bob
Phone      : 9765432109
Address    : City_C
Comparisons: 3

--- SORTED CONTACT DIRECTORY (FOR BINARY SEARCH) ---
No.   Name                 Phone              Address                  
1     Alice                9812345678         City_B                   
2     Bob                  9765432109         City_C                   
3     Charlie              9876543210         City_A                   

2. BINARY SEARCH EXECUTION
Status     : Contact Found at sorted index 2!
Name       : Bob
Phone      : 9765432109
Address    : City_C
Comparisons: 1

SEARCH ALGORITHM COMPARISON
Linear Search Comparisons   : 3 (Worst Case O(n))
Binary Search Comparisons   : 1 (Worst Case O(log n))
```

### Test Case 2: Contact Not Present
**Input:**
```text
Search Target: David
```
**Output:**
```text
Linear Search: Contact Not Found. (Comparisons: 3)
Binary Search: Contact Not Found. (Comparisons: 2)
```

## 8. Conclusion
Successfully implemented Linear and Binary Search along with Bubble Sort on contact directory records. Verified through empirical comparison metrics that Binary Search drastically reduces search comparisons from $O(n)$ to $O(\log n)$ once data is sorted.
