//NAME : Arukala Srushidhar Reddy
//REG.NO : 24BAI10508

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Global pointers for the head and tail of the list
Node* head = NULL;
Node* tail = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list from head to tail
void displayForward() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = head;
    printf("List (forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the list from tail to head
void displayBackward() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = tail;
    printf("List (backward): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
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

    if (current == NULL) {
        printf("Position out of bounds. Cannot insert.\n");
        free(newNode);
        return;
    }

    if (current == tail) {
        insertAtEnd(data);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
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
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete the node from the end of the list
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
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

    Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Cannot delete.\n");
        return;
    }

    if (temp == tail) {
        deleteFromEnd();
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("Deleted %d from position %d.\n", temp->data, position);
    free(temp);
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
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
                displayForward();
                break;
            case 8:
                displayBackward();
                break;
            case 9:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
