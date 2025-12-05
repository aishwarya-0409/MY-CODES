//NAME : Atkuri Yashvani
//REG.NO : 24MEI10027

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global pointer for the top of the stack
Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to add an element to the stack (push)
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to remove an element from the stack (pop)
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1; // Return a sentinel value
    }
    Node* temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    printf("Popped %d from the stack.\n", data);
    return data;
}

// Function to get the top element without removing it (peek)
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    }
    return top->data;
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n--- Stack Menu (Linked List Implementation) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
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
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Top element is: %d\n", data);
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
