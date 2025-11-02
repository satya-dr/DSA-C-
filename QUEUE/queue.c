#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {

    if (rear == MAX - 1){
        return 1;
    }else{
        return 0;
    }

    // The entire above code can be replaced by (both will give same result) --> return rear == MAX-1

}

// Function to check if queue is empty
int isEmpty() {

    if(front == -1 || front > rear){
        return 1;
    }else{
        return 0;
    }

    // The entire above code can be replaced by (both will give same result) --> return front == -1 || front > rear
    
}

// Enqueue operation
void enqueue(int element) {

    // Instead of calling isFull we can manually check as well like showed in the video --> rear == MAX-1
    if (isFull()) {

        printf("Queue Overflow");

    } else {

        if (front == -1)  // First element insertion
            front = 0;

        rear++;
        queue[rear] = element;

        printf("%d inserted into the queue.\n", element);

    }
}

// Dequeue operation
void dequeue() {

    // Instead of calling isEmpty we can manually check as well like showed in the video --> front == -1 || front > rear
    if (isEmpty()) {

        printf("Queue Underflow! No elements to delete.\n");

    } else {

        int item = queue[front];

        front++;
        
        printf("Deleted: %d\n", item);

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

        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");

    }
}

int main() {
    
    enqueue(5);
    enqueue(6);

    enqueue(8);
    enqueue(10);

   

    return 0;
}
