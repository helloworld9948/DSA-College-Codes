#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void insert(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
        return;
    }

    struct node* cur = root;
    struct node* pre = NULL;

    while (cur != NULL) {
        pre = cur;
        if (x < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (x < pre->data)
        pre->left = temp;
    else
        pre->right = temp;
}

struct node* search(int x) {
    struct node* current = root;
    while (current != NULL && current->data != x) {
        if (x < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

struct node* findMin(struct node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct node* deleteNode(struct node* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void preorder(struct node* t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(struct node* t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &x);
                if (search(x) != NULL)
                    printf("Element %d found in the tree.\n", x);
                else
                    printf("Element %d not found in the tree.\n", x);
                break;

            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                printf("Element %d deleted from the tree.\n", x);
                break;

            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}