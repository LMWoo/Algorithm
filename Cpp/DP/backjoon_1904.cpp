// https://www.acmicpc.net/problem/1904

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int a_1;
int a_2;
int out = 0;

int main()
{
    a_1 = 1;
    a_2 = 2;
    
    scanf("%d", &N);
    
    if (N == 1)
    {
        out = a_1;
    }
    else if (N == 2)
    {
        out = a_2;
    }
    else
    {
        for (int i = 2; i < N; ++i)
        {
            out = (a_1 + a_2) % 15746;
            a_1 = a_2;
            a_2 = out;
        }
    }
    
    
    printf("%d", out);
}
