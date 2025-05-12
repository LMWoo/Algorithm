// https://www.acmicpc.net/problem/2655

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Brick
{
    int S;
    int H;
    int W;
    int pos;
    
    Brick(int S, int H, int W, int pos)
    {
        this->S = S;
        this->H = H;
        this->W = W;
        this->pos = pos;
    }
    
    bool operator<(const Brick& temp) const
    {
        return this->S > temp.S;
    }
};

struct DP
{
    int maxH;
    int prev;
    int pos;
    int num;
    
    DP(int maxH, int pos, int num)
    {
        this->maxH = maxH;
        this->prev = -1;
        this->pos = pos;
        this->num = num;
    }
};

vector<Brick> vec(101, Brick(0, 0, 0, 0));
vector<DP> dp(101, DP(0, 0, 0));


int N;
int S, H, W;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &S, &H, &W);
        Brick temp(S, H, W, i);
        vec[i] = temp;
    }
    
    sort(vec.begin(), vec.end());
    
    dp[0].pos = vec[0].pos;
    dp[0].maxH = vec[0].H;
    dp[0].num = 1;
    
    DP max_dp = dp[0];
    
    for (int i = 1; i < N; ++i)
    {
        Brick B_curr = vec[i];
        dp[i].pos = B_curr.pos;
        dp[i].maxH = B_curr.H;
        dp[i].num = 1;
        
        for (int j = 0; j < i; ++j)
        {
            Brick B_prev = vec[j];
            
            if (B_curr.W < B_prev.W)
            {
                if (dp[i].maxH < dp[j].maxH + B_curr.H)
                {
                    dp[i].maxH = dp[j].maxH + B_curr.H;
                    dp[i].prev = j;
                    dp[i].num = dp[j].num + 1;
                }
            }
        }
        if (max_dp.maxH < dp[i].maxH)
        {
            max_dp = dp[i];
        }
    }
    
    printf("%d\n", max_dp.num);
    while(true)
    {
        printf("%d\n", max_dp.pos + 1);
        
        if (max_dp.prev == -1)
        {
            break;
        }
        
        max_dp = dp[max_dp.prev];
    }
    return 0;
}
