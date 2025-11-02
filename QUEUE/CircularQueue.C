#include <stdio.h>
#include <stdlib.h>

#define MAX 4   // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    // Instead of if (rear == MAX-1) ----->
    return (front == 0 && rear == MAX - 1) || front == ((rear + 1) % MAX);
}

// Function to check if queue is empty
int isEmpty() {
    // Instead of front == -1 || front > rear ----->
    return front == -1;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  // First element insertion
            front = 0;

        // Instead of rear++ ----->
        rear = (rear + 1) % MAX;
        queue[rear] = value;

        printf("%d inserted into the queue.\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted: %d\n", queue[front]);

        // If front equals rear reset everything because queue is now empty
        if (front == rear) {
            front = rear = -1;
        } else {
            // Instead of front++ ----->
            front = (front + 1) % MAX;
        }
    }
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i;
        printf("Queue elements: ");
        // Rotate in circular fashion
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);  // Print last element
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(6);
    enqueue(8);
    enqueue(10);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(3);
    enqueue(5);

    display();

    peek();

    // Code to print the array from start to end
    // for(int i=0;i<MAX;i++){
    //     printf("%d ",queue[i]);
    // }

    return 0;
}
