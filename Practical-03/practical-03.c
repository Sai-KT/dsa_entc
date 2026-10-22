/**
 * Practical 03: Contact Directory Management (Linear vs Binary Search)
 * Student: Pushpak Bagade | Roll No: SEA 13 (SE A)
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX_CONTACTS 50

typedef struct Contact {
    char name[30];
    char phone[20];
    char address[50];
} Contact;

/**
 * Reads contact information from user.
 */
void readContacts(Contact c[], int n) {
    printf("\n--- ENTER CONTACT DETAILS ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nContact [%d]:\n", i + 1);
        printf("Name: ");
        scanf("%29s", c[i].name);
        printf("Phone Number: ");
        scanf("%19s", c[i].phone);
        printf("Address: ");
        scanf("%49s", c[i].address);
    }
}

/**
 * Displays all contacts in tabular format.
 */
void displayContacts(const Contact c[], int n) {
    printf("\n=======================================================================\n");
    printf("%-5s %-20s %-18s %-25s\n", "No.", "Name", "Phone", "Address");
    printf("=======================================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-18s %-25s\n", i + 1, c[i].name, c[i].phone, c[i].address);
    }
    printf("=======================================================================\n");
}

/**
 * Performs Linear Search and counts comparisons.
 */
int linearSearch(const Contact c[], int n, const char *key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (strcasecmp(key, c[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Sorts contacts alphabetically by name using Bubble Sort.
 */
void bubbleSortContacts(Contact c[], int n) {
    Contact temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcasecmp(c[j].name, c[j + 1].name) > 0) {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

/**
 * Performs Binary Search on sorted contacts and counts comparisons.
 */
int binarySearch(const Contact c[], int n, const char *key, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        int cmp = strcasecmp(key, c[mid].name);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    Contact contacts[MAX_CONTACTS];
    int n;
    char search_key[30];
    int lin_comp = 0, bin_comp = 0;

    printf("============================================================\n");
    printf("  PRACTICAL 03: CONTACT DIRECTORY (SEARCHING COMPARISON)\n");
    printf("============================================================\n");
    printf("Enter number of contacts: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_CONTACTS) {
        printf("Error: Invalid contact count. Exiting.\n");
        return 1;
    }

    readContacts(contacts, n);

    printf("\n--- ORIGINAL CONTACT DIRECTORY ---\n");
    displayContacts(contacts, n);

    printf("\nEnter name of contact to search: ");
    scanf("%29s", search_key);

    /* --- Linear Search --- */
    printf("\n------------------------------------------------------------\n");
    printf("1. LINEAR SEARCH EXECUTION\n");
    printf("------------------------------------------------------------\n");
    int lin_idx = linearSearch(contacts, n, search_key, &lin_comp);
    if (lin_idx != -1) {
        printf("Status     : Contact Found!\n");
        printf("Name       : %s\n", contacts[lin_idx].name);
        printf("Phone      : %s\n", contacts[lin_idx].phone);
        printf("Address    : %s\n", contacts[lin_idx].address);
    } else {
        printf("Status     : Contact Not Found.\n");
    }
    printf("Comparisons: %d\n", lin_comp);

    /* --- Sort Before Binary Search --- */
    bubbleSortContacts(contacts, n);
    printf("\n--- SORTED CONTACT DIRECTORY (FOR BINARY SEARCH) ---\n");
    displayContacts(contacts, n);

    /* --- Binary Search --- */
    printf("\n------------------------------------------------------------\n");
    printf("2. BINARY SEARCH EXECUTION\n");
    printf("------------------------------------------------------------\n");
    int bin_idx = binarySearch(contacts, n, search_key, &bin_comp);
    if (bin_idx != -1) {
        printf("Status     : Contact Found at sorted index %d!\n", bin_idx + 1);
        printf("Name       : %s\n", contacts[bin_idx].name);
        printf("Phone      : %s\n", contacts[bin_idx].phone);
        printf("Address    : %s\n", contacts[bin_idx].address);
    } else {
        printf("Status     : Contact Not Found.\n");
    }
    printf("Comparisons: %d\n", bin_comp);

    /* --- Comparison Summary --- */
    printf("\n============================================================\n");
    printf("                 SEARCH ALGORITHM COMPARISON\n");
    printf("============================================================\n");
    printf("Target Name                 : %s\n", search_key);
    printf("Linear Search Comparisons   : %d (Worst Case O(n))\n", lin_comp);
    printf("Binary Search Comparisons   : %d (Worst Case O(log n))\n", bin_comp);
    printf("============================================================\n");

    return 0;
}
