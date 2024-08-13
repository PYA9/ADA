#include<stdio.h>

void dij();
void printpath();

int sv, i, j, n, w, v = 0, t, min, count, dist[10], visited[10], cost[10][10], path[10];

void main()
{
    printf("\n\n********* DIJKSTRA'S ALGORITHM *********\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\n\nEnter the cost matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("\n\nThe entered cost matrix is\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    printf("\n\nEnter the source vertex: ");
    scanf("%d", &sv);
    dij();
    printpath();
    printf("\n\n********* ************************ *********");
}

void dij()
{
    count = 2;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[sv][i];
        if (cost[sv][i] == 999)
            path[i] = 0;
        else
            path[i] = sv;
    }
    visited[sv] = 1;

    while (count <= n)
    {
        min = 99;
        for (w = 1; w <= n; w++)
            if (dist[w] < min && !visited[w])
            {
                min = dist[w];
                v = w;
            }
        visited[v] = 1;
        count++;
        for (w = 1; w <= n; w++)
        {
            if (dist[w] > dist[v] + cost[v][w])
            {
                dist[w] = dist[v] + cost[v][w];
                path[w] = v;
            }
        }
    }
}

void printpath()
{
    for (w = 1; w <= n; w++)
    {
        if (visited[w] == 1 && w != sv)
        {
            printf("\n\nThe shortest distance between %d->%d = %d", sv, w, dist[w]);
            t = path[w];
            printf("\nThe path is:\n");
            printf("%d", w);
            while (t != sv)
            {
                printf("<-->%d", t);
                t = path[t];
            }
            printf("<-->%d", sv);
        }
    }
}

