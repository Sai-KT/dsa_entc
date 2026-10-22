# Practical 06: Ticket Reservation System using Circular Queue and Waiting List

## 1. Practical Number
Practical 06

## 2. Practical Title / Aim
Design and implement a Ticket Reservation System in C using a Circular Queue for confirmed seats and a Linear Waiting List with automatic promotion upon cancellation.

## 3. Objective
- Implement Circular Queue semantics for managing a fixed allocation of confirmed resources (tickets).
- Implement a secondary Linear Queue / Array for excess demand (waiting list).
- Demonstrate dynamic resource reallocation: automatically promoting the head of the waiting list into the confirmed queue upon cancellation.
- Handle corner cases: queue full, waiting list overflow, cancellation of arbitrary tickets, and empty queues.

## 4. Algorithm / Logic Used

### A. Ticket Booking (`bookTicket`)
1. **Start**
2. If confirmed queue is NOT full:
   - Enqueue ticket number into circular queue `confirmed`.
   - Print "Ticket Confirmed".
3. Else if waiting list is NOT full (`wait_count < MAX_WAITING`):
   - Append ticket number to `waiting[wait_count++]`.
   - Print "Added to Waiting List".
4. Else:
   - Print "Both Confirmed & Waiting List Full - Booking Rejected".
5. **End**

### B. Ticket Cancellation (`cancelTicket`)
1. **Start**
2. Locate target `ticket_no` in the confirmed circular queue.
3. If not found, report error and return.
4. Shift subsequent elements backwards to maintain circular sequence and decrement `rear`.
5. If waiting list has pending tickets (`wait_count > 0`):
   - Extract first waiting ticket (`waiting[0]`).
   - Shift remaining waiting tickets forward by 1 index and decrement `wait_count`.
   - Enqueue promoted ticket into `confirmed` circular queue.
6. **End**

## 5. Code Implementation
Source code: [practical-06.c](practical-06.c)

```c
void bookTicket(TicketSystem *ts, int ticket_no) {
    if (isConfirmedFull(ts)) {
        if (ts->wait_count >= MAX_WAITING) {
            printf("Both confirmed seats and waiting list are FULL!\n");
            return;
        }
        ts->waiting[ts->wait_count++] = ticket_no;
    } else {
        ts->rear = (ts->rear + 1) % MAX_CONFIRMED;
        ts->confirmed[ts->rear] = ticket_no;
    }
}
```

## 6. Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| :--- | :---: | :---: |
| **Booking (Confirmed)** | $O(1)$ | $O(1)$ |
| **Booking (Waiting List)** | $O(1)$ | $O(1)$ |
| **Cancellation (Search & Shift)** | $O(N)$ where $N \le \text{MAX\_CONFIRMED}$ | $O(1)$ |
| **Promotion from Waiting List** | $O(W)$ where $W \le \text{MAX\_WAITING}$ | $O(1)$ |
| **Display Status** | $O(N + W)$ | $O(1)$ |

## 7. Input / Output & Test Cases

### Test Case 1: Booking Confirmed & Waiting List
**Input:**
- Book tickets: 101, 102, 103, 104, 105 (fills confirmed queue)
- Book ticket: 106 (goes to waiting list)
**Output:**
```text
[CONFIRMED] Ticket 101 booked successfully (Seat confirmed).
...
[CONFIRMED] Ticket 105 booked successfully (Seat confirmed).
[WAITING] Confirmed seats full. Ticket 106 added to WAITING LIST (Position: 1).
```

### Test Case 2: Cancellation & Automatic Promotion
**Action:**
- Cancel ticket 103.
**Output:**
```text
[CANCELLED] Ticket 103 has been successfully cancelled.
[PROMOTED] Waiting ticket 106 is now CONFIRMED!
```
**Display:**
```text
Confirmed Tickets (Active): [101] [102] [104] [105] [106] 
Waiting List (0 / 5): Empty
```

### Test Case 3: Rejection on Full Capacity
**Action:**
- Fill all 5 confirmed and 5 waiting seats.
- Attempt 11th booking.
**Output:**
```text
[ALERT] Both confirmed seats and waiting list are FULL! Booking rejected for ticket 111.
```

## 8. Conclusion
Successfully implemented the Ticket Reservation System in C combining Circular Queue and Linear Waiting List structures. Verified that cancellations dynamically and correctly promote waiting tickets to confirmed status while maintaining FIFO integrity.
