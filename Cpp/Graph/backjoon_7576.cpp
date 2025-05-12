// https://www.acmicpc.net/problem/7576

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int N, M;
int box[1001][1001];
int day[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int out = 0;

bool direction_check(int x, int y)
{
    if (x < 1 || y < 1 || x > M || y > N)
    {
        return false;
    }
    if (box[y][x] != 0)
    {
        return false;
    }
    
    return true;
}

int main()
{
    scanf("%d %d", &M, &N);
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1)
            {
                q.push(make_pair(j, i));
            }
        }
    }
    
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        
        int x = front.first;
        int y = front.second;
        
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (direction_check(xx, yy))
            {
                box[yy][xx] = 1;
                day[yy][xx] = day[y][x] + 1;
                out = max(out, day[yy][xx]);
                q.push(make_pair(xx, yy));
            }
        }
    }
    
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (box[i][j] == 0)
            {
                out = -1;
            }
        }
    }
    
    printf("%d", out);
    
    return 0;
}
