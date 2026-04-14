#include <stdio.h>
        return head;
    }

    struct node *second = NULL, *temp2 = NULL;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (second == NULL) {
            second = newnode;
            temp2 = second;
        } else {
            temp2->next = newnode;
            newnode->prev = temp2;
            temp2 = newnode;
        }
    }

    if (head == NULL)
        head = second;
    else {
        struct node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;

        temp1->next = second;
        second->prev = temp1;
    }

    display(head);
    return head;
}

// Main
int main() {
    struct node *head = NULL;
    int choice, x;

    while (1) {
        printf("Enter operation\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("4: Reverse\n");
        printf("5: Concatenate\n");
        printf("6: Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &x);
                head = insertEnd(head, x);
                break;

            case 2:
                scanf("%d", &x);
                head = deleteValue(head, x);
                break;

            case 3:
                display(head);
                break;

            case 4:
                head = reverse(head);
                break;

            case 5:
                head = concatenate(head);
                break;

            case 6:
                printf("Exit\n");
                exit(0);
        }
    }
}