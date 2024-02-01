#include <stdio.h>
#include <stdlib.h>

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

void inOrder(struct Node* root) {
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

void preOrder(struct Node* root) {
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

void postOrder(struct Node* root) {
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

struct Node* search(struct Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return root; // Key not found

    if (current->left == NULL) {
        struct Node* temp = current->right;
        free(current);
        if (parent == NULL)
            return temp; // Root node deleted
        if (parent->left == current)
            parent->left = temp;
        else
            parent->right = temp;
    } else if (current->right == NULL) {
        struct Node* temp = current->left;
        free(current);
        if (parent == NULL)
            return temp; // Root node deleted
        if (parent->left == current)
            parent->left = temp;
        else
            parent->right = temp;
    } else {
        struct Node* temp = minValueNode(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;

    printf("Binary Search Tree Operations\n");
    printf("1. Insert\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Search\n");
    printf("6. Delete\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;

            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node with key %d deleted.\n", key);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
