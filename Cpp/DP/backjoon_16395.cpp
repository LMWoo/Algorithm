// https://www.acmicpc.net/problem/16395

#include <stdio.h>

int n, k;
int arr[31][31];

int main()
{
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[0][1] = 1;
    
    for (int i = 2; i <= 30; ++i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    scanf("%d %d", &n, &k);
    printf("%d", arr[n][k-1]);
    return 0;
}
