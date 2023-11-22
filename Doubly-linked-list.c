#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

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

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;
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
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
    {
        head->prev = temp;
    }

    head = temp;
}

void delete (int x)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n\t\t List is empty");
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != x)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n\t\t Element not found");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display()
{
    struct node *current = head;
    printf("\n\t\t List elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int x, ch;
    printf("\n\t Doubly Linked List operations");
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
