// https://www.acmicpc.net/problem/2178

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int i, j;
char str[101];

queue<pair<int, int>> q;
int arr[101][101];
int dist[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool direction_check(int x, int y)
{
    if (x < 1 || y < 1 || x > M || y > N)
    {
        return false;
    }
    if (!arr[y][x])
    {
        return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (i = 1; i <= N; ++i)
    {
        scanf("%s", str);
        
        for (j = 0; str[j]; ++j)
        {
            arr[i][j + 1] = str[j] - '0';
        }
    }
    
    
    arr[1][1] = 0;
    dist[1][1] = 1;
    q.push(make_pair(1, 1));
    
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        
        int x = front.first;
        int y = front.second;
        
        for (i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (direction_check(xx, yy))
            {
                arr[yy][xx] = 0;
                dist[yy][xx] = dist[y][x] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }
    
    printf("%d", dist[N][M]);
    
    return 0;
}
