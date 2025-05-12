// https://www.acmicpc.net/problem/1197

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Data
{
    int a;
    int b;
    int weight;
    
    Data(int a, int b, int weight)
    {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    
    bool operator<(const Data& temp) const
    {
        return this->weight < temp.weight;
    }
};

int V, E;
int a, b, c;

vector<Data> v;
int arr[10001];

int find(int a)
{
    if (arr[a] == a)
        return a;
    else{
        return arr[a] = find(arr[a]);
    }
}

int sum = 0;

int main(){
    scanf("%d %d", &V, &E);
    
    for (int i = 1; i <= E; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(Data(a, b, c));
    }
    for (int i = 1; i <= V; ++i)
    {
        arr[i] = i;
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); ++i)
    {
        int a = find(v[i].a);
        int b = find(v[i].b);
        
        if (a != b)
        {
            sum += v[i].weight;
            arr[a] = b;
        }
    }
    
    printf("%d", sum);
    return 0;
}
