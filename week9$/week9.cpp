#include <cstdio>
#include <cstring>

#define MAX_COLS 5
#define MOD 1000000007

int dp[2][1 << MAX_COLS], N, M, curr;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    if (N < M)
    {
        int tmp = N;
        N = M;
        M = tmp;
    }
    curr = 0;
    dp[0][(1 << M) - 1] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            curr ^= 1;
            memset(dp[curr], 0, sizeof(dp[curr]));
            for (int state = 0; state < (1 << M); ++state)
            {
                if (state & (1 << (M - 1))){
                	(dp[curr][(state << 1) - (1 << M)] += dp[curr ^ 1][state]) %= MOD;
                }
                if (i && !(state & (1 << (M - 1)))){
                	(dp[curr][(state << 1) + 1] += dp[curr ^ 1][state]) %= MOD;
                }
                if (j && (state & (1 << (M - 1))) && !(state & 1)){
                	(dp[curr][(state << 1) - (1 << M) + 3] += dp[curr ^ 1][state]) %= MOD;
                }
            }
        }
    }
    printf("%d\n", dp[curr][(1 << M) - 1]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
