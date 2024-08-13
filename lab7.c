#include <stdio.h>

int main() {
    int i, selItem = 0, max_qty, availCap, n;
    float sum = 0, unitProfit;
    int weight[20], profit[20];

    printf("Enter no of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the values of each item: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter maximum volume of knapsack: ");
    scanf("%d", &max_qty);
    availCap = max_qty;

    while (availCap > 0) {
        unitProfit = 0;
        for (i = 0; i < n; i++) {
            if (((float)profit[i]) / ((float)weight[i]) > unitProfit) {
                unitProfit = ((float)profit[i]) / ((float)weight[i]);
                selItem = i;
            }
        }
        if (weight[selItem] > availCap) {
            printf("Quantity of item number %d added is %d\n", (selItem + 1), availCap);
            sum += availCap * unitProfit;
            availCap = -1;
        } else {
            printf("Quantity of item number %d added is %d\n", (selItem + 1), weight[selItem]);
            availCap -= weight[selItem];
            sum += (float)profit[selItem];
            profit[selItem] = 0;
        }
    }
    printf("The total profit is %.2f\n", sum);
    return 0;
}

