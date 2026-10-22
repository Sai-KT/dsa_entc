/**
 * Practical 01: Right-Angled Number Pattern Generation
 * Student: Pushpak Bagade | Roll No: SEA 13 (SE A)
 * Academic Year: 2026-27
 */

#include <stdio.h>

/**
 * Function: printNumberPattern
 * ----------------------------
 * Generates and prints a right-angled numeric triangle pattern of n rows.
 * @param n: Number of rows in the pattern
 */
void printNumberPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main(void) {
    int n;

    printf("========================================\n");
    printf("   PRACTICAL 01: NUMBER PATTERN\n");
    printf("========================================\n");
    printf("Enter number of rows (n): ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("\nGenerated Pattern:\n");
    printNumberPattern(n);

    return 0;
}
