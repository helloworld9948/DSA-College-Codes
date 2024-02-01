#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;

void create_insert(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\n \t Memory allocation failed");
        return;
    }

    ptr->data = x;
    ptr->prev = NULL;

    if (head == NULL) {
        ptr->next = NULL;
        head = ptr;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    printf("\n \t Node created and inserted: %d", x);
}

void deletion() {
    struct node *ptr;
    if (head == NULL) {
        printf("\n\t Doubly linked list Underflow\n");
    } else {
        ptr = head;
        printf("\n \t \t Deleted node: %d", ptr->data);
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(ptr);
    }
}

void traversals() {
    struct node *ptr;
    printf("\n \t Traversals: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int ch, x;

    printf("\n \t Doubly Linked List Operations\n");
    printf("\n \t ------------------------------");
    printf("\n \t Create & Insert --> 1");
    printf("\n \t Deletion        --> 2");
    printf("\n \t Traversal       --> 3");
    printf("\n \t Exit            --> 4");
    printf("\n \t -----------------------------\n");

    while (1) {
        printf("\n \t Enter your choice --> ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n \t Enter value to insert: ");
                scanf("%d", &x);
                create_insert(x);
                break;
            case 2:
                deletion();
                break;
            case 3:
                traversals();
                break;
            case 4:
                return 0;
            default:
                printf("\t \t Invalid choice...");
        }
    }

    return 0;
}
