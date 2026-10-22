# Practical 07: Singly Linked List (SLL) Operations

## 1. Practical Number
Practical 07

## 2. Practical Title / Aim
Design and implement a dynamic Singly Linked List (SLL) in C to perform fundamental list operations: creation/appending, arbitrary position insertion, formatted display, position-based deletion, and in-place iterative reversal.

## 3. Objective
- Understand dynamic memory allocation (`malloc`, `free`) and self-referential structures in C.
- Implement pointer manipulation for node insertion and deletion at arbitrary positions without data shifting.
- Implement in-place reversal of a singly linked list using the 3-pointer iterative technique (`prev`, `curr`, `next`).
- Avoid common pointer bugs including dangling pointers, memory leaks, and segmentation faults.

## 4. Algorithm / Logic Used

### A. Arbitrary Position Insertion (`insertAtPosition`)
1. **Start**
2. Allocate memory for `newNode` and set its data.
3. If `position == 1`:
   - Set `newNode->next = head`.
   - Update `head = newNode`.
4. Else:
   - Traverse to node at position `position - 1` using pointer `temp`.
   - If `temp == NULL`, position is invalid (out of bounds).
   - Set `newNode->next = temp->next`.
   - Set `temp->next = newNode`.
5. **End**

### B. In-Place Reversal Algorithm (`reverseList`)
1. **Start**
2. Initialize three pointers: `prev = NULL`, `curr = head`, `next = NULL`.
3. While `curr != NULL`:
   1. Store next node: `next = curr->next`.
   2. Reverse current pointer: `curr->next = prev`.
   3. Advance previous pointer: `prev = curr`.
   4. Advance current pointer: `curr = next`.
4. Update `head = prev`.
5. **End**

## 5. Code Implementation
Source code: [practical-07.c](practical-07.c)

```c
void reverseList(Node **head) {
    Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
```

## 6. Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| :--- | :---: | :---: |
| **Insertion at Head ($pos=1$)** | $O(1)$ | $O(1)$ |
| **Insertion at Position $k$** | $O(k) \le O(n)$ | $O(1)$ |
| **Deletion at Head ($pos=1$)** | $O(1)$ | $O(1)$ |
| **Deletion at Position $k$** | $O(k) \le O(n)$ | $O(1)$ |
| **List Traversal / Display** | $O(n)$ | $O(1)$ |
| **Iterative Reversal** | $O(n)$ | $O(1)$ |

- **Space Complexity:** Total memory is $O(n)$ proportional to number of nodes dynamically allocated on the heap.

## 7. Input / Output & Test Cases

### Test Case 1: Creation & Display
**Input:**
- Add nodes: `Apple`, `Banana`, `Cherry`
**Output:**
```text
Linked List: [Apple] -> [Banana] -> [Cherry] -> NULL
```

### Test Case 2: Insertion at Arbitrary Position
**Input:**
- Insert `Mango` at position 2
**Output:**
```text
[SUCCESS] Inserted 'Mango' at position 2.
Linked List: [Apple] -> [Mango] -> [Banana] -> [Cherry] -> NULL
```

### Test Case 3: Deletion at Arbitrary Position
**Input:**
- Delete node at position 3 (`Banana`)
**Output:**
```text
[SUCCESS] Deleted node with data 'Banana' from position 3.
Linked List: [Apple] -> [Mango] -> [Cherry] -> NULL
```

### Test Case 4: In-Place Reversal
**Action:**
- Choose Option 5 (Reverse List)
**Output:**
```text
[SUCCESS] Singly Linked List reversed successfully.
Linked List: [Cherry] -> [Mango] -> [Apple] -> NULL
```

## 8. Conclusion
Successfully implemented dynamic Singly Linked List operations in C with heap allocation and cleanup. Demonstrated efficient in-place pointer reversal in $O(n)$ time and $O(1)$ auxiliary space without creating duplicate nodes.
