#include<stdio.h>

int a[20][20], q[20], visit[20], n, i, j, f = 0, r = 0;

void BFS(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && !visit[i])
            q[++r] = i;
    }
    if (f <= r) {
        visit[q[f]] = 1;
        BFS(q[f++]);
    }
    return;
}

int main() {
    int vno;
    printf("\n \n \t \t BFS Traversals using Queue ");
    printf("\n \t \t ---------------------------");
    printf("\n \n \t \t  Enter no of vertices:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visit[i] = 0;
    }

    printf("\n \t \t   Enter adjacency Matrix :\n");
    for (i = 1; i <= n; i++) {
        printf("\n \t \t    Enter Row %d : ", i);
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\n \t \t   Enter the starting vertex:");
    scanf("%d", &vno);

    BFS(vno);

    printf("\n \t \t   The BFS Traversals: ");
    for (i = 1; i <= n; i++) {
        if (visit[i]) {
            printf("%d ", i);
        } else {
            printf(" \n \t \t   Not possible. Graph is unconnected \n");
            return 0;
        }
    }

    return 0;
}
