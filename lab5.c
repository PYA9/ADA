#include <stdio.h>

void topo();
int ad[10][10], i, j, n, k;

void main() {
    printf("\n\n********** TOPOLOGICAL SORTING *********\n\n");
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("\n\nEnter the adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &ad[i][j]);
        }
    }
    printf("\n\nThe entered adjacency matrix is\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", ad[i][j]);
        }
        printf("\n");
    }
    topo();
}

void topo() 
{
    int v[10], in = 1, flag = 0, count = 0, f = 1;
    while (f) 
    {
        count++;
        for (i = 1; i <= n; i++) {
            flag = 0;
            for (j = 1; j <= n; j++) {
                if (ad[j][i] != 0 || v[j] == i) 
                {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                v[in++] = i;
                for (k = 1; k <= n; k++)
                    ad[i][k] = 0;
            }
        }
        if (count == n)
            f = 0;
    }
    if (in < n)
        printf("\n\nTopological ordering is not possible\n");
    else {
        printf("\n\nTopological ordering is possible\n");
        printf("\nOrdering is:\t");
        for (i = 1; i <= n; i++)
            printf("%d\t", v[i]);
    }
    printf("\n**********************************************");
}

