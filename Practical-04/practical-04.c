/**
 * Practical 04: Decimal to Binary Conversion using Stack ADT
 * Roll Number: 13 | Division: SE A
 * Academic Year: 2026-27
 */

#include <stdio.h>
#include <stdbool.h>

#define STACK_CAPACITY 64

typedef struct Stack {
    int items[STACK_CAPACITY];
    int top;
} Stack;

/**
 * Initializes the stack.
 */
void initStack(Stack *s) {
    s->top = -1;
}

/**
 * Checks if the stack is full.
 */
bool isFull(const Stack *s) {
    return s->top == STACK_CAPACITY - 1;
}

/**
 * Checks if the stack is empty.
 */
bool isEmpty(const Stack *s) {
    return s->top == -1;
}

/**
 * Pushes an element onto the stack.
 */
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    s->items[++(s->top)] = value;
}

/**
 * Pops an element from the stack.
 */
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

/**
 * Converts a non-negative decimal integer to binary using Stack LIFO property.
 */
void decimalToBinary(int decimal) {
    Stack s;
    initStack(&s);

    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    int temp = decimal;
    while (temp > 0) {
        int remainder = temp % 2;
        push(&s, remainder);
        temp /= 2;
    }

    printf("Binary equivalent of %d is: ", decimal);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main(void) {
    int decimal;

    printf("============================================================\n");
    printf("   PRACTICAL 04: DECIMAL TO BINARY CONVERSION USING STACK\n");
    printf("============================================================\n");
    printf("Enter a non-negative decimal number: ");

    if (scanf("%d", &decimal) != 1 || decimal < 0) {
        printf("Error: Please enter a valid non-negative integer (>= 0).\n");
        return 1;
    }

    decimalToBinary(decimal);

    return 0;
}
