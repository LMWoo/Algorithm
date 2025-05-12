// https://www.acmicpc.net/problem/11657

#include <climits>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int A;
    int B;
    int C;
    
    Edge(int A, int B, int C)
    {
        this->A = A;
        this->B = B;
        this->C = C;
    }
};

vector<pair<int, int>> map[501];
long long dist[501];

int N, M;
int A, B, C;

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= M; ++i)
    {
        scanf("%d %d %d", &A, &B, &C);
        map[A].push_back(make_pair(B, C));
    }
    
    for (int i = 1; i <= N; ++i)
    {
        dist[i] = INT_MAX;
    }
    
    dist[1] = 0;
    
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[j] != INT_MAX)
            {
                for (int k = 0; k < map[j].size(); ++k)
                {
                    int v = map[j][k].first;
                    int w = map[j][k].second;
                    
                    if (dist[v] > dist[j] + w)
                    {
                        if (i == M)
                        {
                            printf("%d", -1);
                            return 0;
                        }
                        dist[v] = dist[j] + w;
                    }
                }
            }
        }
    }
    
    for (int i = 2; i <= N; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            printf("%d\n", -1);
            continue;
        }
        printf("%lld\n", dist[i]);
    }
    return 0;
}
