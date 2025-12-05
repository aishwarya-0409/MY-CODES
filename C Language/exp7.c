//Name: Atkuri Yashvani
//Reg.no: 24MEI10027

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Global queue array and front/rear pointers
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1 && front == 0) || (rear + 1 == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data;
        printf("Enqueued %d onto the queue.\n", data);
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue element.\n");
        return -1; // Return a sentinel value
    } else {
        int data = queue[front];
        if (front == rear) { // Last element in the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue.\n", data);
        return data;
    }
}

// Function to get the front element without removing it
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    } else {
        return queue[front];
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\n--- Queue Menu (Array Implementation) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Front element is: %d\n", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
