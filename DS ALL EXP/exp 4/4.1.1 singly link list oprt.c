#include <stdio.h>
struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList* initializeList() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert(struct LinkedList* list, int data, int position) {
     if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } 
    else {
        struct Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
    printf("Element %d inserted at position %d\n", data, position);


     
    
}
void deleteNode(struct LinkedList* list, int position) {
   if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp;

    if (position == 0) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
    } 
    else {
        struct Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    list->size--;
    printf("Element at position %d deleted\n", position);
