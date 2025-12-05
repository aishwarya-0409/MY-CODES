#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for passenger
typedef struct Passenger {
    char name[50];
    int vip; // 1 = VIP, 0 = Regular
    struct Passenger* next;
    struct Passenger* prev;
} Passenger;

// Deque with head and tail pointers
typedef struct {
    Passenger* front;
    Passenger* rear;
} Deque;

// Initialize deque
void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
}

// Create new passenger node
Passenger* createPassenger(char* name, int vip) {
    Passenger* p = (Passenger*)malloc(sizeof(Passenger));
    strcpy(p->name, name);
    p->vip = vip;
    p->next = p->prev = NULL;
    return p;
}

// Insert VIP at front
void addVIP(Deque* dq, char* name) {
    Passenger* p = createPassenger(name, 1);
    if (dq->front == NULL) {
        dq->front = dq->rear = p;
    } else {
        p->next = dq->front;
        dq->front->prev = p;
        dq->front = p;
    }
    printf("VIP Passenger %s added at front.\n", name);
}

// Insert Regular at rear
void addRegular(Deque* dq, char* name) {
    Passenger* p = createPassenger(name, 0);
    if (dq->rear == NULL) {
        dq->front = dq->rear = p;
    } else {
        dq->rear->next = p;
        p->prev = dq->rear;
        dq->rear = p;
    }
    printf("Regular Passenger %s added at rear.\n", name);
}

// Remove from front (check-in)
void checkIn(Deque* dq) {
    if (dq->front == NULL) {
        printf("No passengers to check-in.\n");
        return;
    }
    Passenger* temp = dq->front;
    printf("Passenger %s checked-in.\n", temp->name);
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
}

// Remove from rear (cancellation)
void cancel(Deque* dq) {
    if (dq->rear == NULL) {
        printf("No passengers to cancel.\n");
        return;
    }
    Passenger* temp = dq->rear;
    printf("Passenger %s cancelled booking.\n", temp->name);
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
}

// Display queue
void display(Deque* dq) {
    if (dq->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Passenger* temp = dq->front;
    printf("Current Queue: ");
    while (temp != NULL) {
        if (temp->vip) printf("[VIP:%s] ", temp->name);
        else printf("[%s] ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("Name: Atkuri Yashvani\n");
    printf("Reg.No:24MEI10027\n");
    printf("Date: 5/9/2025\n");
    Deque dq;
    initDeque(&dq);

    addRegular(&dq, "Alice");
    addVIP(&dq, "Dr. Smith");
    addRegular(&dq, "Bob");
    display(&dq);

    checkIn(&dq);
    display(&dq);

    cancel(&dq);
    display(&dq);

    return 0;
}