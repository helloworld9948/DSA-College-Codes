#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
        return;
    }

    last = head;
    while (last->next != head)
    {
        last = last->next;
    }

    last->next = temp;
    temp->next = head;
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

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        temp->next = head;
        last->next = temp;
        head = temp;
    }
}

void delete (int x)
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("\n\t\t List is empty");
        return;
    }

    temp = head;
    prev = NULL;

    do
    {
        if (temp->data == x)
        {
            if (prev != NULL)
            {
                prev->next = temp->next;
            }
            else
            {
                struct node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                head = temp->next;
                last->next = head;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    printf("\n\t\t Element not found");
}

void display()
{
    struct node *current;
    if (head == NULL)
    {
        printf("\n\t\t List is empty");
        return;
    }

    current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;

    } while (current != head);
}

int main()
{
    int x, ch;
    printf("\n\t Circular Linked List operations");
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
