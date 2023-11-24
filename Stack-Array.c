#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        printf("\n\t\t Stack overflow");
        return;
    }

    top++;
    stack[top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("\n\t\t Stack underflow");
        return;
    }

    printf("\n\t\t Popped element: %d", stack[top]);
    top--;
}

void traversal()
{
    if (top == -1)
    {
        printf("\n\t\t Stack is empty");
        return;
    }

    printf("\n\t\t Stack elements: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX_SIZE - 1;
}

int getTop()
{
    if (top == -1)
    {
        printf("\n\t\t Stack is empty");
        return -1; // You might want to choose a suitable value for an empty stack
    }
    return stack[top];
}

int main()
{
    int x, ch;
    printf("\n\t Stack operations by array");
    printf("\n\t-------------------------------\n");
    printf("\n\t\t Push -> 1");
    printf("\n\t\t Pop  -> 2");
    printf("\n\t\t Traversal -> 3");
    printf("\n\t\t Is Empty -> 4");
    printf("\n\t\t Is Full  -> 5");
    printf("\n\t\t Get Top  -> 6");
    printf("\n\t\t Exit -> 7");
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
            printf("\n\t\t Is Empty: %s", isEmpty() ? "Yes" : "No");
            break;
        case 5:
            printf("\n\t\t Is Full: %s", isFull() ? "Yes" : "No");
            break;
        case 6:
            printf("\n\t\t Top element: %d", getTop());
            break;
        case 7:
            return 0;
        default:
            printf("\n\t\t Invalid choice --\n");
            break;
        }
    }
}
