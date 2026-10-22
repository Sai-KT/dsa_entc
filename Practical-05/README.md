# Practical 05: Circular Queue Implementation for Parcel Management

## 1. Practical Number
Practical 05

## 2. Practical Title / Aim
Implement a menu-driven Circular Queue data structure using an array in C for a real-world Parcel Dispatch Management System to perform enqueue, dequeue, and display operations.

## 3. Objective
- Understand the limitation of standard linear queues (unusable memory slots upon deletion).
- Implement Circular Queue utilizing modulo arithmetic (`%`) to recycle deallocated memory space.
- Develop functions to handle queue boundary conditions: Overflow (`front == (rear + 1) % SIZE`) and Underflow (`front == -1`).
- Simulate a FIFO parcel dispatch system with optimal memory reuse.

## 4. Algorithm / Logic Used

### A. Enqueue Operation (`enqueue`)
1. **Start**
2. Check for Queue Overflow: If `front == (rear + 1) % CAPACITY`, print "Queue is Full" and return.
3. If queue is empty (`front == -1`):
   - Set `front = 0`, `rear = 0`.
4. Else:
   - Increment `rear = (rear + 1) % CAPACITY`.
5. Store new `parcel_id` in `parcels[rear]`.
6. **End**

### B. Dequeue Operation (`dequeue`)
1. **Start**
2. Check for Queue Underflow: If `front == -1`, print "Queue is Empty" and return.
3. Retrieve item at `parcels[front]`.
4. If `front == rear` (single element remaining):
   - Reset queue to empty: `front = -1`, `rear = -1`.
5. Else:
   - Increment `front = (front + 1) % CAPACITY`.
6. Return retrieved parcel.
7. **End**

## 5. Code Implementation
Source code: [practical-05.c](practical-05.c)

```c
bool isFull(const CircularQueue *q) {
    return (q->front == (q->rear + 1) % QUEUE_CAPACITY);
}

void enqueue(CircularQueue *q, int parcel_id) {
    if (isFull(q)) {
        printf("Parcel queue is FULL!\n");
        return;
    }
    if (isEmpty(q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % QUEUE_CAPACITY;
    q->parcels[q->rear] = parcel_id;
}
```

## 6. Complexity Analysis
- **Time Complexity:**
  - **Enqueue Operation:** $O(1)$ constant time (direct index calculation using modulo).
  - **Dequeue Operation:** $O(1)$ constant time.
  - **Display Operation:** $O(k)$ where $k \le \text{CAPACITY}$ is the number of active elements.
  - **Best, Average, and Worst Case:** $O(1)$ for both insertion and deletion.
- **Space Complexity:**
  - **Auxiliary Space:** $O(1)$ runtime auxiliary space.
  - **Data Structure Space:** $O(N)$ where $N = 5$ is fixed capacity.

## 7. Input / Output & Test Cases

### Test Case 1: Fill Queue to Capacity
**Input:**
```text
Add parcels: 101, 102, 103, 104, 105
Option 1 -> Add Parcel: 106
```
**Output:**
```text
[SUCCESS] Parcel 101 added successfully at position 0.
[SUCCESS] Parcel 102 added successfully at position 1.
[SUCCESS] Parcel 103 added successfully at position 2.
[SUCCESS] Parcel 104 added successfully at position 3.
[SUCCESS] Parcel 105 added successfully at position 4.

[ERROR] Parcel queue is FULL! Cannot accept parcel 106.
```

### Test Case 2: Dispatch and Wrap-around (Modulo Reuse)
**Action:**
- Dispatch 2 parcels (101 and 102).
- Add new parcel 107.
**Output:**
```text
[DISPATCHED] Parcel 101 has been dispatched from position 0.
[DISPATCHED] Parcel 102 has been dispatched from position 1.
[SUCCESS] Parcel 107 added successfully at position 0. (Circular Wrap-around verified!)
```

### Test Case 3: Empty Queue Underflow
**Action:**
- Dispatch remaining parcels until empty.
- Try dispatching once more.
**Output:**
```text
[ERROR] Parcel queue is EMPTY! No parcels to dispatch.
```

## 8. Conclusion
Successfully implemented a Circular Queue in C demonstrating constant time $O(1)$ enqueue and dequeue operations. Verified that modulo arithmetic prevents false overflow by continuously recycling vacated array positions.
