#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("\n\t\t Memory allocation failed");
        exit(1);
    }
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int x)
{
    if (node == NULL)
    {
        return createNode(x);
    }

    if (x < node->data)
    {
        node->left = insert(node->left, x);
    }
    else if (x > node->data)
    {
        node->right = insert(node->right, x);
    }

    return node;
}

struct Node *findMin(struct Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct Node *deleteNode(struct Node *root, int x)
{
    if (root == NULL)
    {
        printf("\n\t\t Element %d not found", x);
        return root;
    }

    if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node *search(struct Node *root, int x)
{
    if (root == NULL || root->data == x)
    {
        return root;
    }

    if (x < root->data)
    {
        return search(root->left, x);
    }
    return search(root->right, x);
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int x, ch;
    printf("\n\t Binary Search Tree operations");
    printf("\n\t-------------------------------\n");
    printf("\n\t\t Insert -> 1");
    printf("\n\t\t Delete -> 2");
    printf("\n\t\t Search -> 3");
    printf("\n\t\t Inorder Traversal -> 4");
    printf("\n\t\t Preorder Traversal -> 5");
    printf("\n\t\t Postorder Traversal -> 6");
    printf("\n\t\t Exit -> 7");
    printf("\n\t-------------------------------\n");

    while (1)
    {
        printf("\n\t\t Enter choice -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t Enter element to insert: ");
            scanf("%d", &x);
            root = insert(root, x);
            break;
        case 2:
            printf("\n\t\t Enter element to delete: ");
            scanf("%d", &x);
            root = deleteNode(root, x);
            break;
        case 3:
            printf("\n\t\t Enter element to search: ");
            scanf("%d", &x);
            if (search(root, x) != NULL)
                printf("\n\t\t Element %d found", x);
            else
                printf("\n\t\t Element %d not found", x);
            break;
        case 4:
            if (root == NULL)
            {
                printf("\n\t\t Tree is empty");
            }
            else
            {
                printf("\n\t\t Inorder Traversal: ");
                inorderTraversal(root);
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("\n\t\t Tree is empty");
            }
            else
            {
                printf("\n\t\t Preorder Traversal: ");
                preorderTraversal(root);
            }
            break;
        case 6:
            if (root == NULL)
            {
                printf("\n\t\t Tree is empty");
            }
            else
            {
                printf("\n\t\t Postorder Traversal: ");
                postorderTraversal(root);
            }
            break;
        case 7:
            return 0;
        default:
            printf("\n\t\t Invalid choice --\n");
            break;
        }
    }
}
