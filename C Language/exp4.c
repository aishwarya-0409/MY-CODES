//Name: Atkuri Yashvani
//Reg.No: 24MEI10027

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global pointer for the head of the list
Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = head;
    printf("List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself for a single-node list
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end.\n", data);
}

// Function to insert a node at a specific position
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == head) { // We have traversed the entire list and position is out of bounds
        printf("Position out of bounds. Cannot insert.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

// Function to delete the node from the beginning of the list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete the node from the end of the list
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        Node* last = head;
        Node* prev = NULL;
        while (last->next != head) {
            prev = last;
            last = last->next;
        }
        prev->next = head;
        temp = last;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

// Function to delete a node from a specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
        if (current == head) { // Reached head before finding position
            printf("Position out of bounds. Cannot delete.\n");
            return;
        }
    }

    prev->next = current->next;
    printf("Deleted %d from position %d.\n", current->data, position);
    free(current);
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}