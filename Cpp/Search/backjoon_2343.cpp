// https://www.acmicpc.net/problem/2343

#include <stdio.h>
#include <algorithm>
#include <numeric>

int arr[1000001];
int M, N;

int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= M; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int answer = -1;

    int left = *std::max_element(arr + 1, arr + M + 1); 
    int right = std::accumulate(arr + 1, arr + M + 1, 0); 

    while (left <= right)
    {
        int middle = (left + right) / 2;

        int blueray_num = 1;
        int remain = middle;

        for (int i = 1; i <= M; ++i)
        {
            if (remain < arr[i])
            {
                blueray_num += 1;
                remain = middle;
            }
            remain -= arr[i];
        }

        if (blueray_num <= N)
        {
            answer = middle;
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}