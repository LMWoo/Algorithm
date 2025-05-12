// https://www.acmicpc.net/problem/1929

#include <stdio.h>

using namespace std;

char arr[1000001];
int M, N;

int main()
{
    scanf("%d %d", &M, &N);
    for (int i = 2; i <= N; ++i)
    {
        if (!arr[i])
        {
            if (M <= i)
            {
                printf("%d\n", i);
            }
            for (int j = i; j <= N; j += i)
            {
                arr[j] = 1;
            }
        }
    }
    
    return 0;
}
