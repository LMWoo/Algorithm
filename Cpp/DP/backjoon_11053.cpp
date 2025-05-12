// https://www.acmicpc.net/problem/11053

#include <stdio.h>
#include <algorithm>

using namespace std;

int N = 0;
int arr[1001] = {0, };
int len[1001] = {0, };
int out = 0;

int main()
{
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    len[0] = 1;
    
    for (int i = 1; i <= N; ++i)
    {
        int max_len = 0;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                max_len = max(max_len, len[j]);
            }
        }
        len[i] = max_len + 1;
        out = max(out, len[i]);
    }
    
    printf("%d", out);
    return 0;
}
