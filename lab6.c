#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (a > b ? a : b)

void knapsack();
void optimal();

int i, j, x[10], n, m, v[10][10], w[10], p[10], item=0;

void main() {
    printf("\n***KNAPSACK PROBLEM***\n\n");
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("\n\nEnter the weight of each item : ");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("\n\nEnter the profit of each item : ");
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("\n\nEnter the Knapsack capacity : ");
    scanf("%d", &m);
    knapsack();
    printf("\n\nThe contents of the knapsack table are:\n");
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    optimal();
}

void knapsack() {
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            if(i == 0 || j == 0) 
                v[i][j] = 0;
            else if(j < w[i]) 
                v[i][j] = v[i-1][j];
            else 
                v[i][j] = max(v[i-1][j], v[i-1][j-w[i]] + p[i]);
        }
    }
}

void optimal() {
    int i = n, j = m;
    while(i != 0 && j != 0) {
        if(v[i][j] != v[i-1][j]) {
            x[i] = 1; 
            j = j - w[i];
        }
        i = i - 1;
    }
    printf("\n\nOptimal solution is %d\n\n", v[n][m]);
    printf("selected items are");
    for(i = 1; i <= n; i++) {
        if(x[i] == 1) {
            printf("%d", i);
            item = 1;
        }
    }
    if (item == 0)
        printf("NIL \n\tSorry! No item can be placed in knapsack.\n");
    printf("\n*************************************************");
}

