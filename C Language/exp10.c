//Name : Atkuri Yashvani
//Reg.no: 24MEI10027

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global pointer to the rear of the circular queue
Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return rear == NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    if (isEmpty()) {
        rear = newNode;
        rear->next = rear; // Make it a circular list
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d onto the queue.\n", data);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue element.\n");
        return -1; // Return a sentinel value
    }
    int data;
    Node* temp = rear->next;
    if (rear == temp) { // Only one element in the queue
        data = temp->data;
        free(temp);
        rear = NULL;
    } else {
        data = temp->data;
        rear->next = temp->next;
        free(temp);
    }
    printf("Dequeued %d from the queue.\n", data);
    return data;
}

// Function to get the front element without removing it (peek)
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return rear->next->data;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = rear->next;
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != rear->next);
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n--- Circular Queue Menu (Linked List Implementation) ---\n");
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
