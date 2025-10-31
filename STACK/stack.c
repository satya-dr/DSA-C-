#include <stdio.h>

#define STACK_CAPACITY 4   // Maximum number of elements the stack can hold

// Global stack array and top pointer
static int stack[STACK_CAPACITY];
static int top = -1;   // -1 indicates the stack is currently empty

// Function to display all elements in the stack
void displayStack() {
    printf("\nCurrent Stack State:\n");

    if (top == -1) {
        printf("Stack is empty.\n\n");
        return;
    }

    // Print stack from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("| %d |\n", stack[i]);
    }
    printf("\n");
}

// Function to push an element onto the stack
int push(int element) {
    if (top == STACK_CAPACITY - 1) {
        printf("Error: Stack Overflow (cannot push %d)\n", element);
        return 0;   // Push failed
    }

    /*
    Same as:
        top++;
        stack[top] = element;
    */
    stack[++top] = element;  // Increment top and insert element
    return 1;   // Push successful
}

// Function to pop (remove) the top element from the stack
int pop() {
    if (top == -1) {
        printf("Error: Stack Underflow (no element to pop)\n");
        return 0;   // Pop failed
    }

    top--;  // Simply move the top pointer down
    return 1;    // Pop successful
}

// Function to view the top element without removing it
void peek() {
    if (top == -1) {
        printf("Stack is empty, nothing to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

int main() {
    // Sample operations on stack
    push(3);
    push(5);
    push(7);

    displayStack();

    pop();
    displayStack();

    peek();

    return 0;
}
