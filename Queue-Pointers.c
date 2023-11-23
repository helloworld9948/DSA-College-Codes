#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n\t\t Memory allocation failed");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\n\t\t Queue is empty");
        return;
    }

    struct node *temp = front;
    printf("\n\t\t Dequeued element: %d", temp->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);
}

void display()
{
    struct node *current = front;
    printf("\n\t\t Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int x, ch;
    printf("\n\t Queue operations by linked list");
    printf("\n\t-------------------------------\n");
    printf("\n\t\t Enqueue -> 1");
    printf("\n\t\t Dequeue  -> 2");
    printf("\n\t\t Display -> 3");
    printf("\n\t\t Exit -> 4");
    printf("\n\t-------------------------------\n");
    while (1)
    {
        printf("\n\t\t Enter choice -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t Enter element to enqueue: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("\n\t\t Invalid choice --\n");
            break;
        }
    }
}
