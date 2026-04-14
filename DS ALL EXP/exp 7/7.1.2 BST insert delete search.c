#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_OPS 100


typedef struct Node {
    
    //code here...
        
    int data;
    struct Node* left;
	struct Node* right;
    
    
    
} Node;


Node* createNode(int data) {
    
    //code here...
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
    return newNode;
    
    
    
}


Node* insert(Node *root, int data) {
     if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
    
    //code here...
    
    
    
}


Node* findMin(Node *root) {
    
    
    //code here...
    
           while (root && root->left != NULL) root = root->left;
    return root;
    
    
}


Node* deleteNode(Node *root, int key) {
}