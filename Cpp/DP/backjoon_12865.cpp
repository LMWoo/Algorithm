// https://www.acmicpc.net/problem/12865

#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[101][11];
pair<int, int> p[101];

int N, K;
int W, V;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d %d", &W, &V);
        p[i] = make_pair(W, V);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= K; ++j)
        {
            if (i == 1)
            {
                if (j - p[i].first >= 0)
                {
                    dp[i][j] = p[i].second;
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - p[i].first >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i].first] + p[i].second);
                }
            }
        }
    }
    
    printf("%d", dp[N][K]);
    
    return 0;
}

