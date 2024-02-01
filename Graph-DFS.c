#include <stdio.h>

int n, a[10][10], visited[10];

void DFS(int v) {
    int i;
    visited[v] = 1;

    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            printf("\n \t \t \t %d -> %d \n \t \t \t", v, i);
            DFS(i);
        }
    }
}

int main() {
    int i, j, sno;

    printf("\n\n \t DFS Traversals by Adjacency Matrix");
    printf("\n \t ----------------------------------\n");
    printf("\n \t Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0; 
    }

    printf("\n \t Enter adjacency matrix \n");

    for (i = 1; i <= n; i++) {
        printf("\n \t \t \t Row %d : ", i);
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\n \t Enter traversals starting node: ");
    scanf("%d", &sno);

    printf("\n \t DFS Traversals: \n");
    DFS(sno);

    return 0;
}
