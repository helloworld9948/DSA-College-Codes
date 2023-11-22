#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void append(int x)
{
    struct node *temp, *last;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n\t\t Memory allocation failed");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (top == NULL)
    {
        top = temp;
        return;
    }

    last = top;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;
}

void prepend(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n\t\t Memory allocation failed");
        return;
    }

    temp->data = x;
    temp->next = top;
    top = temp;
}

void delete (int x)
{
    struct node *temp, *prev;
    if (top == NULL)
    {
        printf("\n\t\t Stack is underflow");
        return;
    }

    temp = top;
    if (temp->data == x)
    {
        top = temp->next;
        free(temp);
        return;
    }

    prev = NULL;
    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n\t\t Element not found");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    struct node *current = top;
    printf("\n\t\t Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int x, ch;
    printf("\n\t Stack operations by linked list");
    printf("\n\t-------------------------------\n");
    printf("\n\t\t Append -> 1");
    printf("\n\t\t Prepend  -> 2");
    printf("\n\t\t Delete -> 3");
    printf("\n\t\t Display -> 4");
    printf("\n\t\t Exit -> 5");
    printf("\n\t-------------------------------\n");
    while (1)
    {
        printf("\n\t\t Enter choice -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t Enter element to append: ");
            scanf("%d", &x);
            append(x);
            break;
        case 2:
            printf("\n\t\t Enter element to prepend: ");
            scanf("%d", &x);
            prepend(x);
            break;
        case 3:
            printf("\n\t\t Enter element to delete: ");
            scanf("%d", &x);
            delete (x);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("\n\t\t Invalid choice --\n");
            break;
        }
    }
}
