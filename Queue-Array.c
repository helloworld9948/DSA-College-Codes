#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("\n\t\t Queue is full");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        printf("\n\t\t Queue is empty");
        return;
    }

    printf("\n\t\t Dequeued element: %d", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\n\t\t Queue is empty");
        return;
    }

    printf("\n\t\t Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int x, ch;
    printf("\n\t Queue operations by array");
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
