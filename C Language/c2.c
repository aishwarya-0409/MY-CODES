#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end
void append(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find maximum element in the linked list
int findMax(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return INT_MIN;  // Return minimum possible integer
    }

    int max = head->data;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }

    return max;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Append elements
    append(&head, 15);
    append(&head, 8);
    append(&head, 23);
    append(&head, 42);
    append(&head, 7);

    // Display the list
    displayList(head);

    // Find and print the maximum
    int maxElement = findMax(head);
    if (maxElement != INT_MIN)
        printf("Maximum element in the linked list: %d\n", maxElement);

    printf("Press Enter to exit....");
    getchar(); // This will wait for user input before closing

    return 0;
}