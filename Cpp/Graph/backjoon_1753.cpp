// https://www.acmicpc.net/problem/1753

#include <climits>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge
{
    int v;
    int w;
    
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
    
    bool operator<(const Edge& temp) const
    {
        return this->w > temp.w;
    }
};

vector<pair<int, int>> map[20001];
priority_queue<Edge> pq;
int dist[20001];

int V, E;
int K;
int u, v, w;

int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        map[u].push_back(make_pair(v, w));
    }
    
    for (int i = 1; i <= V; ++i)
    {
        dist[i] = INT_MAX;
    }
    
    dist[K] = 0;
    pq.push(Edge(K, dist[K]));
    
    while(!pq.empty())
    {
        Edge top = pq.top();
        pq.pop();
        
        v = top.v;
        w = top.w;
        
        for (int i = 0; i < map[v].size(); ++i)
        {
            int next_v = map[v][i].first;
            int next_w = map[v][i].second + w;
            
            if (dist[next_v] > next_w)
            {
                dist[next_v] = next_w;
                pq.push(Edge(next_v, dist[next_v]));
            }
        }
    }
    
    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }
    
    return 0;
}

