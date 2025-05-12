// https://www.acmicpc.net/problem/2252

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[32001];
int degree[32001];
queue<int> q;

int N, M;
int A, B;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; ++i)
    {
        scanf("%d %d", &A, &B);
        map[A].push_back(B);
        degree[B]++;
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        printf("%d ", front);
        
        for (int i = 0; i < map[front].size(); ++i)
        {
            int v = map[front][i];
            degree[v]--;
            if (!degree[v])
            {
                q.push(v);
            }
        }
    }
}

