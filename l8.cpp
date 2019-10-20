#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int cutRod(int price[], int n)
{
    int pieces[n + 1][n + 1];
    int val[n + 1];
    val[0] = 0;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        int max_val = INT_MIN, ind = -1;
        for (j = 1; j <= i; j++)
        {
            if (max_val < price[j - 1] + val[i - j])
            {
                if (pieces[i - j][j] != 1)
                {
                    ind = j;
                }
            }
            max_val = max(max_val, price[j - 1] + val[i - j]);
        }
        val[i] = max_val;
        for (int k = 0; k <= n; k++)
        {
            pieces[i][k] = pieces[i - ind][k];
        }
        pieces[i][ind] = 1;
    }
    for (int i = 0; i <= n; ++i)
        if (pieces[n][i] == 1)
            printf("%d ", i);
    printf("\n");
    return val[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("El maximo valor obtenible es: %d \n", cutRod(arr, size));
    getchar();
    return 0;
}