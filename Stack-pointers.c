#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *top = NULL;

void push(int x)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (top == NULL)
    {
        temp->data = x;
        temp->next = NULL;
        top = temp;
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\n\t\t Stack is underflow");
        return;
    }
    else
    {
        struct node* temp;
        printf("\n\t\t Popped element: %d", top->data);
        temp = top;
        top = top->next;
        free(temp);
    }
}

void traversal()
{
    if (top == NULL)
    {
        printf("\n\t\t Stack is underflow");
        return;
    }
    struct node* pi = top;
    printf("\n\t\t Stack elements: ");
    while (pi != NULL)
    {
        printf("%d ", pi->data);
        pi = pi->next;
    }
}

int main()
{
    int x, ch;
    printf("\n\t Stack operations by linked list");
    printf("\n\t-------------------------------\n");
    printf("\n\t\t Push -> 1");
    printf("\n\t\t Pop  -> 2");
    printf("\n\t\t Traversal -> 3");
    printf("\n\t\t Exit -> 4");
    printf("\n\t-------------------------------\n");
    while (1)
    {
        printf("\n\t\t Enter choice -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t Enter element to push: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            traversal();
            break;
        case 4:
            return 0;
        default:
            printf("\n\t\t Invalid choice --\n");
            break;
        }
    }
}