#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inOrderRecursive(struct Node* root) {
    if (root != NULL) {
        inOrderRecursive(root->left);
        printf("%d ", root->data);
        inOrderRecursive(root->right);
    }
}

void inOrderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

void preOrderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

void preOrderNonRecursive(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void postOrderRecursive(struct Node* root) {
    if (root != NULL) {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        printf("%d ", root->data);
    }
}

void postOrderNonRecursive(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
	        printf("\n1. Insert\n");
        printf("2. In-order Recursive Traversal\n");
        printf("3. In-order Non-Recursive Traversal\n");
        printf("4. Pre-order Recursive Traversal\n");
        printf("5. Pre-order Non-Recursive Traversal\n");
        printf("6. Post-order Recursive Traversal\n");
        printf("7. Post-order Non-Recursive Traversal\n");
        printf("8. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("\n");
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\n");
                printf("In-order Recursive Traversal: ");
                inOrderRecursive(root);
                printf("\n");
                break;

            case 3:
               printf("\n");
                printf("In-order Non-Recursive Traversal: ");
                inOrderNonRecursive(root);
                printf("\n");
                break;

            case 4:
            	printf("\n");
                printf("Pre-order Recursive Traversal: ");
                preOrderRecursive(root);
                printf("\n");
                break;

            case 5:
            	printf("\n");
                printf("Pre-order Non-Recursive Traversal: ");
                preOrderNonRecursive(root);
                printf("\n");
                break;

            case 6:
            	printf("\n");
                printf("Post-order Recursive Traversal: ");
                postOrderRecursive(root);
                printf("\n");
                break;

            case 7:
            	printf("\n");
                printf("Post-order Non-Recursive Traversal: ");
                postOrderNonRecursive(root);
                printf("\n");
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}