/**
 * Practical 07: Singly Linked List (SLL) Operations
 * Roll Number: 13 | Division: SE A
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[30];
    struct Node *next;
} Node;

/**
 * Creates a new node with given string data.
 */
Node* createNode(const char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

/**
 * Appends a node to the end of the singly linked list.
 */
void appendNode(Node **head, const char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/**
 * Inserts a node at a specified 1-based position.
 */
void insertAtPosition(Node **head, const char *data, int position) {
    if (position < 1) {
        printf("[ERROR] Position must be >= 1.\n");
        return;
    }

    Node *newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("[SUCCESS] Inserted '%s' at position 1.\n", data);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("[ERROR] Position %d out of bounds (List too short).\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("[SUCCESS] Inserted '%s' at position %d.\n", data, position);
}

/**
 * Deletes a node at a specified 1-based position.
 */
void deleteAtPosition(Node **head, int position) {
    if (*head == NULL) {
        printf("[ERROR] List is empty! Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("[ERROR] Position must be >= 1.\n");
        return;
    }

    Node *toDelete = NULL;

    if (position == 1) {
        toDelete = *head;
        *head = (*head)->next;
        printf("[SUCCESS] Deleted node with data '%s' from position 1.\n", toDelete->data);
        free(toDelete);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("[ERROR] Position %d out of bounds.\n", position);
        return;
    }

    toDelete = temp->next;
    temp->next = toDelete->next;
    printf("[SUCCESS] Deleted node with data '%s' from position %d.\n", toDelete->data, position);
    free(toDelete);
}

/**
 * Reverses the singly linked list using the 3-pointer iterative technique.
 */
void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    printf("[SUCCESS] Singly Linked List reversed successfully.\n");
}

/**
 * Traverses and displays the singly linked list.
 */
void displayList(const Node *head) {
    if (head == NULL) {
        printf("\n[INFO] List is empty (NULL).\n");
        return;
    }

    printf("\nLinked List: ");
    const Node *temp = head;
    while (temp != NULL) {
        printf("[%s] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * Frees all allocated memory in the linked list.
 */
void freeList(Node **head) {
    Node *curr = *head;
    Node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int main(void) {
    Node *head = NULL;
    int choice, position;
    char buffer[30];

    do {
        printf("\n============================================\n");
        printf("    SINGLY LINKED LIST (SLL) OPERATIONS\n");
        printf("============================================\n");
        printf("1. Create / Append Node\n");
        printf("2. Insert at Position\n");
        printf("3. Display List\n");
        printf("4. Delete from Position\n");
        printf("5. Reverse List\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: {
                int more = 1;
                do {
                    printf("Enter node data (string): ");
                    scanf("%29s", buffer);
                    appendNode(&head, buffer);
                    printf("Add another node? (1 for Yes, 0 for No): ");
                    if (scanf("%d", &more) != 1) more = 0;
                } while (more == 1);
                break;
            }

            case 2:
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                printf("Enter node data: ");
                scanf("%29s", buffer);
                insertAtPosition(&head, buffer, position);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 5:
                reverseList(&head);
                displayList(head);
                break;

            case 6:
                freeList(&head);
                printf("\nMemory freed. Exited successfully.\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1 through 6.\n");
        }
    } while (choice != 6);

    return 0;
}
