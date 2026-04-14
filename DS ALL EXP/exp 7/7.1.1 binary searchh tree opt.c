#include <stdio.h>
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main
int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found)
                    printf("Value not found\n");
                break;
            }

            case 6:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}