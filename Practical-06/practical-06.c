/**
 * Practical 06: Ticket Reservation System using Circular Queue & Waiting List
 * Roll Number: 13 | Division: SE A
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_CONFIRMED 5
#define MAX_WAITING 5

typedef struct TicketSystem {
    int confirmed[MAX_CONFIRMED];
    int front;
    int rear;
    int waiting[MAX_WAITING];
    int wait_count;
} TicketSystem;

/**
 * Initializes the ticket reservation system.
 */
void initSystem(TicketSystem *ts) {
    ts->front = -1;
    ts->rear = -1;
    ts->wait_count = 0;
}

/**
 * Checks if confirmed queue is full.
 */
bool isConfirmedFull(const TicketSystem *ts) {
    return (ts->front == (ts->rear + 1) % MAX_CONFIRMED);
}

/**
 * Checks if confirmed queue is empty.
 */
bool isConfirmedEmpty(const TicketSystem *ts) {
    return (ts->front == -1);
}

/**
 * Books a ticket. If confirmed seats are full, adds to waiting list.
 */
void bookTicket(TicketSystem *ts, int ticket_no) {
    if (isConfirmedFull(ts)) {
        if (ts->wait_count >= MAX_WAITING) {
            printf("\n[ALERT] Both confirmed seats and waiting list are FULL! Booking rejected for ticket %d.\n", ticket_no);
            return;
        }
        ts->waiting[ts->wait_count++] = ticket_no;
        printf("\n[WAITING] Confirmed seats full. Ticket %d added to WAITING LIST (Position: %d).\n", 
               ticket_no, ts->wait_count);
    } else {
        if (isConfirmedEmpty(ts)) {
            ts->front = 0;
            ts->rear = 0;
        } else {
            ts->rear = (ts->rear + 1) % MAX_CONFIRMED;
        }
        ts->confirmed[ts->rear] = ticket_no;
        printf("\n[CONFIRMED] Ticket %d booked successfully (Seat confirmed).\n", ticket_no);
    }
}

/**
 * Cancels a ticket and automatically promotes the first waiting passenger.
 */
void cancelTicket(TicketSystem *ts, int ticket_no) {
    if (isConfirmedEmpty(ts)) {
        printf("\n[ERROR] No active bookings found to cancel.\n");
        return;
    }

    int curr = ts->front;
    int found_pos = -1;

    // Search for ticket in confirmed circular queue
    while (true) {
        if (ts->confirmed[curr] == ticket_no) {
            found_pos = curr;
            break;
        }
        if (curr == ts->rear) break;
        curr = (curr + 1) % MAX_CONFIRMED;
    }

    if (found_pos == -1) {
        printf("\n[ERROR] Ticket %d not found in confirmed reservations.\n", ticket_no);
        return;
    }

    // Shift elements backward to fill the vacated slot
    int idx = found_pos;
    while (idx != ts->rear) {
        int next_idx = (idx + 1) % MAX_CONFIRMED;
        ts->confirmed[idx] = ts->confirmed[next_idx];
        idx = next_idx;
    }

    // Adjust rear or reset if queue becomes empty
    if (ts->front == ts->rear) {
        ts->front = -1;
        ts->rear = -1;
    } else {
        ts->rear = (ts->rear - 1 + MAX_CONFIRMED) % MAX_CONFIRMED;
    }

    printf("\n[CANCELLED] Ticket %d has been successfully cancelled.\n", ticket_no);

    // Promote the first passenger from waiting list if available
    if (ts->wait_count > 0) {
        int promoted_ticket = ts->waiting[0];
        
        // Shift remaining waiting list passengers forward
        for (int j = 0; j < ts->wait_count - 1; j++) {
            ts->waiting[j] = ts->waiting[j + 1];
        }
        ts->wait_count--;

        // Enqueue promoted passenger into confirmed queue
        if (isConfirmedEmpty(ts)) {
            ts->front = 0;
            ts->rear = 0;
        } else {
            ts->rear = (ts->rear + 1) % MAX_CONFIRMED;
        }
        ts->confirmed[ts->rear] = promoted_ticket;

        printf("[PROMOTED] Waiting ticket %d is now CONFIRMED!\n", promoted_ticket);
    }
}

/**
 * Displays confirmed bookings and waiting list tickets.
 */
void displayBookings(const TicketSystem *ts) {
    printf("\n============================================\n");
    printf("         CURRENT RESERVATION STATUS\n");
    printf("============================================\n");

    printf("Confirmed Tickets (%s): ", isConfirmedEmpty(ts) ? "Empty" : "Active");
    if (!isConfirmedEmpty(ts)) {
        int i = ts->front;
        while (true) {
            printf("[%d] ", ts->confirmed[i]);
            if (i == ts->rear) break;
            i = (i + 1) % MAX_CONFIRMED;
        }
    } else {
        printf("None");
    }

    printf("\nWaiting List (%d / %d): ", ts->wait_count, MAX_WAITING);
    if (ts->wait_count > 0) {
        for (int i = 0; i < ts->wait_count; i++) {
            printf("[%d] ", ts->waiting[i]);
        }
    } else {
        printf("Empty");
    }
    printf("\n============================================\n");
}

int main(void) {
    TicketSystem ts;
    initSystem(&ts);

    int choice, ticket_no;

    do {
        printf("\n============================================\n");
        printf("   TICKET RESERVATION & WAITING LIST SYSTEM\n");
        printf("============================================\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Bookings\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter ticket number to book: ");
                if (scanf("%d", &ticket_no) == 1) {
                    bookTicket(&ts, ticket_no);
                }
                break;

            case 2:
                printf("Enter ticket number to cancel: ");
                if (scanf("%d", &ticket_no) == 1) {
                    cancelTicket(&ts, ticket_no);
                }
                break;

            case 3:
                displayBookings(&ts);
                break;

            case 4:
                printf("\nExiting Ticket Reservation System. Thank you!\n");
                break;

            default:
                printf("\nInvalid option! Please enter a choice between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
