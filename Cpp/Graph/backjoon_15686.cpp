// https://www.acmicpc.net/problem/15686

#include <climits>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> H;
vector<pair<int, int>> C;

int N, M;
int arr[14];
int in[51][51];
int out = INT_MAX;

void DFS(int s, int L)
{
    if (L == M)
    {
        int sum_dist = 0;
        for (int i = 0; i < H.size(); ++i)
        {
            int min_dist = INT_MAX;
            for (int j = 0; j < L; ++j)
            {
                pair<int, int> H_P = H[i];
                pair<int, int> C_P = C[arr[j]];
                
                int dist = abs(H_P.first - C_P.first) + abs(H_P.second - C_P.second);
                min_dist = min(min_dist, dist);
            }
            sum_dist += min_dist;
        }
        out = min(out, sum_dist);
        return;
    }
    else
    {
        for (int i = s; i < C.size(); ++i)
        {
            arr[L] = i;
            DFS(i + 1, L + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &in[i][j]);
            if (in[i][j] == 1)
            {
                H.push_back(make_pair(i, j));
            }
            else if (in[i][j] == 2)
            {
                C.push_back(make_pair(i, j));
            }
        }
    }
    
    DFS(0, 0);
    printf("%d", out);
    
    return 0;
}
