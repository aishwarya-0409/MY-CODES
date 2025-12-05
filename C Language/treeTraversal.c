#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for Preorder Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for Postorder Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
   
    
    struct Node* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);
    root->left->left = createNode(5);
    root->left->right = createNode(4);
    
    printf("Inorder Traversal: ");
    inorderTraversal(root); // Expected: 4 2 5 1 3
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root); // Expected: 1 2 4 5 3
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root); // Expected: 4 5 2 3 1
    printf("\n");

    

    return 0;
}