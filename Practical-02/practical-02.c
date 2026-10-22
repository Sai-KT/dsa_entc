/**
 * Practical 02: Student Database Management System
 * Student: Pushpak Bagade | Roll No: SEA 13 (SE A)
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

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

/**
 * Creates records for n students.
 */
void createStudents(Student s[], int n) {
    printf("\n--- ENTER STUDENT RECORDS ---\n");
    for (int i = 0; i < n; i++) {
        printf("\n[Record %d of %d]\n", i + 1, n);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter Student Name: ");
        scanf("%49s", s[i].name);
        printf("Enter Program (e.g., Computer_Engg): ");
        scanf("%29s", s[i].program);
        printf("Enter Subject 1 Name: ");
        scanf("%19s", s[i].sub1_name);
        printf("Enter Subject 1 Marks: ");
        scanf("%d", &s[i].sub1_marks);
        printf("Enter Subject 2 Name: ");
        scanf("%19s", s[i].sub2_name);
        printf("Enter Subject 2 Marks: ");
        scanf("%d", &s[i].sub2_marks);

        s[i].total_marks = s[i].sub1_marks + s[i].sub2_marks;
        s[i].average = (float)s[i].total_marks / 2.0f;
    }
    printf("\nAll %d records saved successfully!\n", n);
}

/**
 * Displays all student records in a structured format.
 */
void displayStudents(const Student s[], int n) {
    if (n == 0) {
        printf("\nDatabase is empty! Please create records first.\n");
        return;
    }

    printf("\n========================================================================================\n");
    printf("%-8s %-16s %-15s %-10s %-8s %-10s %-8s %-8s %-8s\n",
           "Roll No", "Name", "Program", "Sub1", "Marks", "Sub2", "Marks", "Total", "Average");
    printf("========================================================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-16s %-15s %-10s %-8d %-10s %-8d %-8d %-8.2f\n",
               s[i].roll_no, s[i].name, s[i].program,
               s[i].sub1_name, s[i].sub1_marks,
               s[i].sub2_name, s[i].sub2_marks,
               s[i].total_marks, s[i].average);
    }
    printf("========================================================================================\n");
}

/**
 * Searches for a student by roll number using Linear Search.
 */
void searchStudent(const Student s[], int n, int search_key) {
    if (n == 0) {
        printf("\nDatabase is empty! Please create records first.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].roll_no == search_key) {
            printf("\n--- STUDENT RECORD FOUND ---");
            printf("\nRoll Number : %d", s[i].roll_no);
            printf("\nName        : %s", s[i].name);
            printf("\nProgram     : %s", s[i].program);
            printf("\n%s Marks    : %d", s[i].sub1_name, s[i].sub1_marks);
            printf("\n%s Marks    : %d", s[i].sub2_name, s[i].sub2_marks);
            printf("\nTotal Marks : %d", s[i].total_marks);
            printf("\nAverage     : %.2f\n", s[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d NOT FOUND.\n", search_key);
    }
}

int main(void) {
    Student database[MAX_STUDENTS];
    int count = 0;
    int choice, search_roll;

    do {
        printf("\n========================================\n");
        printf("  STUDENT DATABASE MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Create / Add Students\n");
        printf("2. Display All Records\n");
        printf("3. Search by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\nEnter number of students to add: ");
                int n;
                if (scanf("%d", &n) == 1 && n > 0 && (count + n) <= MAX_STUDENTS) {
                    createStudents(&database[count], n);
                    count += n;
                } else {
                    printf("Invalid count or exceeds maximum capacity (%d)!\n", MAX_STUDENTS);
                }
                break;

            case 2:
                displayStudents(database, count);
                break;

            case 3:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &search_roll);
                searchStudent(database, count, search_roll);
                break;

            case 4:
                printf("\nExiting Student Database System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
