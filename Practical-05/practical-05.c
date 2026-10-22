/**
 * Practical 05: Circular Queue Implementation for Parcel Management System
 * Student: Pushpak Bagade | Roll No: SEA 13 (SE A)
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 5

typedef struct CircularQueue {
    int parcels[QUEUE_CAPACITY];
    int front;
    int rear;
} CircularQueue;

/**
 * Initializes the circular queue to empty state.
 */
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

/**
 * Checks if circular queue is full.
 */
bool isFull(const CircularQueue *q) {
    return (q->front == (q->rear + 1) % QUEUE_CAPACITY);
}

/**
 * Checks if circular queue is empty.
 */
bool isEmpty(const CircularQueue *q) {
    return (q->front == -1);
}

/**
 * Adds a new parcel to the circular queue.
 */
void enqueue(CircularQueue *q, int parcel_id) {
    if (isFull(q)) {
        printf("\n[ERROR] Parcel queue is FULL! Cannot accept parcel %d.\n", parcel_id);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % QUEUE_CAPACITY;
    }

    q->parcels[q->rear] = parcel_id;
    printf("\n[SUCCESS] Parcel %d added successfully at position %d.\n", parcel_id, q->rear);
}

/**
 * Dispatches (removes) a parcel from the front of the queue.
 */
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("\n[ERROR] Parcel queue is EMPTY! No parcels to dispatch.\n");
        return -1;
    }

    int dispatched = q->parcels[q->front];
    printf("\n[DISPATCHED] Parcel %d has been dispatched from position %d.\n", dispatched, q->front);

    if (q->front == q->rear) {
        // Last element removed, reset queue to empty
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % QUEUE_CAPACITY;
    }

    return dispatched;
}

/**
 * Displays all parcels currently awaiting dispatch.
 */
void displayQueue(const CircularQueue *q) {
    if (isEmpty(q)) {
        printf("\n[INFO] Parcel queue is currently empty.\n");
        return;
    }

    printf("\n--- PARCELS IN DISPATCH QUEUE ---\n");
    int i = q->front;
    int count = 1;
    while (true) {
        printf("%d. Parcel ID: %d (Slot %d)\n", count++, q->parcels[i], i);
        if (i == q->rear) break;
        i = (i + 1) % QUEUE_CAPACITY;
    }
    printf("---------------------------------\n");
}

int main(void) {
    CircularQueue queue;
    initQueue(&queue);

    int choice, parcel_id;

    do {
        printf("\n============================================\n");
        printf("    PARCEL DISPATCH MANAGEMENT (CIRCULAR QUEUE)\n");
        printf("============================================\n");
        printf("1. Add Parcel (Enqueue)\n");
        printf("2. Dispatch Parcel (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter parcel number to add: ");
                if (scanf("%d", &parcel_id) == 1) {
                    enqueue(&queue, parcel_id);
                } else {
                    printf("Invalid parcel ID.\n");
                }
                break;

            case 2:
                dequeue(&queue);
                break;

            case 3:
                displayQueue(&queue);
                break;

            case 4:
                printf("\nExited Parcel Management System successfully.\n");
                break;

            default:
                printf("\nInvalid option! Please enter a choice between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
