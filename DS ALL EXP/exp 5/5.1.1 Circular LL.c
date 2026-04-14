#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(   int n    ) {
	
// write your code here...
  if (n <= 0) return NULL;

    struct node *first = NULL, *temp = NULL, *newnode;
    int x;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;

        if (first == NULL) {
            first = newnode;
            newnode->next = first;
            temp = first;
        } else {
            temp->next = newnode;
            newnode->next = first;
            temp = newnode;
        }
    }
    return first;
}

// Count nodes
int countNodes(struct node *first) {
    if (first == NULL) return 0;

    int count = 0;
    struct node *temp = first;
    do {
        count++;
        temp = temp->next;
    } while (temp != first);

    return count;


}

// Traverse CLL
void traverseListInCLL( struct node *first     ) {

// write your code here...
if (first == NULL) return;

    struct node *temp = first;
