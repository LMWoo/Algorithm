// https://www.acmicpc.net/problem/11404

#include <climits>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int d[101][101];
int n, m;
int a, b, c;

int main()
{
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                d[i][j] = 0;
                continue;
            }
            d[i][j] = INT_MAX;
        }
    }
    
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }
    
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int d_ik = d[i][k];
                int d_kj = d[k][j];
                int d_ij = d[i][j];
                if (d_ik == INT_MAX || d_kj == INT_MAX)
                {
                    continue;
                }
                d[i][j] = min(d_ij, d_ik + d_kj);
            }
        }
    }
   
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (d[i][j] == INT_MAX)
            {
                printf("%d ", 0);
                continue;
            }
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
