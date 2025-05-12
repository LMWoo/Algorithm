// https://www.acmicpc.net/problem/1005

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> q;
vector<int> map[1001];

int node[1001];
int times[1001];
int degree[1001];

int T;
int N, K;
int X, Y;
int W;

int i;

void Clear()
{
    for (i = 0; i <= 1000; ++i)
    {
        map[i].clear();
        node[i] = 0;
        times[i] = 0;
        degree[i] = 0;
        while(!q.empty())
        {
            q.pop();
        }
    }
}

void Input()
{
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; ++i)
    {
        scanf("%d", &node[i]);
        times[i] = node[i];
    }
    
    for (i = 1; i <= K; ++i)
    {
        scanf("%d %d", &X, &Y);
        map[X].push_back(Y);
        degree[Y]++;
    }
    
    scanf("%d", &W);
}

void Solution()
{
    for (i = 1; i <= N; ++i)
    {
        if (!degree[i])
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        X = q.front();
        q.pop();
        
        for (i = 0; i < map[X].size(); ++i)
        {
            Y = map[X][i];
            times[Y] = max(times[Y], node[Y] + times[X]);
            
            if (--degree[Y] == 0)
            {
                q.push(Y);
            }
        }
    }
    
    printf("%d\n", times[W]);
}

int main()
{
    scanf("%d", &T);

    for (int t = 0; t < T; ++t)
    {
        Clear();
        Input();
        Solution();
    }

    return 0;
}
