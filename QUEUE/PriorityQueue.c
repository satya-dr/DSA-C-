#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the priority queue

int queue[MAX];       // Stores elements
int priority[MAX];    // Stores corresponding priorities
int front = -1, rear = -1;   // Queue pointers

// Function to check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue operation (insert element with priority at rear)
void enqueue(int value, int p) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  // First element insertion
            front = 0;

        rear++;
        queue[rear] = value;
        priority[rear] = p;

        printf("%d with priority %d inserted into the queue.\n", value, p);
    }
}

// Dequeue operation (remove element with highest priority)
// If two elements have the same priority, the one inserted first will be deleted
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        int pos = front;
        int highestPriority = priority[front];

        // Find position of element with the highest priority
        for (int i = front + 1; i <= rear; i++) {
            if (priority[i] > highestPriority) {
                highestPriority = priority[i];
                pos = i;
            }
        }

        printf("Deleted: %d (priority %d)\n", queue[pos], priority[pos]);

        // Shift elements left after deletion
        for (int i = pos; i < rear; i++) {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }
        rear--;

       
    }
}

// Peek operation (get element with highest priority without deleting)
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int pos = front;
        int highestPriority = priority[front];

        for (int i = front + 1; i <= rear; i++) {
            if (priority[i] > highestPriority) {
                highestPriority = priority[i];
                pos = i;
            }
        }

        printf("Front element (highest priority): %d (priority %d)\n", queue[pos], priority[pos]);
    }
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements (with priorities):\n");
        for (int i = front; i <= rear; i++) {
            printf("%d (p=%d)  ", queue[i], priority[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10, 2);
    enqueue(5, 1);
    enqueue(15, 3);
    enqueue(20, 4);

    display();

    dequeue();
    display();

    peek();

    return 0;
}
