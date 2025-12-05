//NAME : Atkuri Yashvani
//REG.NO : 24MEI10027


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Global stack array and top pointer
int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to add an element to the stack
void push(int data) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        top++;
        stack[top] = data;
        printf("Pushed %d onto the stack.\n", data);
    }
}

// Function to remove an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1; // Return a sentinel value
    } else {
        int data = stack[top];
        top--;
        printf("Popped %d from the stack.\n", data);
        return data;
    }
}

// Function to get the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display the elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("\n--- Stack Menu (Array Implementation) ---\n");
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
