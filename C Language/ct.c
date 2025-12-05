#include <stdio.h>
#include <stdlib.h>

#define V 4   // Number of vertices

// Function to print adjacency matrix
void printMatrix(int adj[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// Function to print adjacency list
void printList(int adj[V][V]) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", 'A' + i);
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                printf("%c ", 'A' + j);
            }
        }
        printf("\n");
    }
}

int main() {
    int adj[V][V] = {0};

    // Edges: (A,B), (A,C), (B,D), (C,D)
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][3] = adj[3][2] = 1;

    // Print matrix and list
    printMatrix(adj);
    printList(adj);

    return 0;
}
