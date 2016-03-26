#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline int read()
{
	int x = 0, f = 1, t = getchar();
	while(t < 48 || t > 57) t == 45 ? f = -1 : 0, t = getchar();
	if(t > 47 && t < 58) x = t - 48;
	return x * f;
}

const int n = 30;
const int maxn = n + 1;
int a[maxn][maxn],b[maxn];
int ans[maxn];
int cnt;

inline void swapRow(const int x, const int y)
{
	if(x != y)
	{
		for(int i = 1; i <= n; ++i)
		{
			swap(a[x][i], a[y][i]);
		}
		swap(b[x], b[y]);
	}
}

void gaussxor()
{
	for(int i = 1; i <= n; ++i)
	{
		int r = 0;
		for(int j = i; j <= n; ++j)
		{
			if(a[j][i])
			{
				r = j;
			} 
		}
		swapRow(i, r);
		for(int j = i + 1; j <= n; ++j)
		{
			if(a[j][i])
			{
				for(int k = 1; k <= n; ++k)
				{
					a[j][k] = a[i][k] ^ a[j][k];
				}	
				b[j] = b[i] ^ b[j];	
			}
		}
	}
	for(int i = n; i >= 1; --i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			b[i] = b[i] ^ (a[i][j] * ans[j]);
			a[i][j] = 0;
		}
		ans[i] = b[i];
		if(ans[i])
		{
			cnt++;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int x1,y1,x2,y2;
	for(int i = 1; i <= n; i++)
	{
		x1 = (i - 1) % 6;
		y1 = (i - 1) / 6;
		for(int j = 1; j <= n; j++)
		{
			x2 = (j - 1) % 6;
			y2 = (j - 1) / 6;
			if(x1 == x2 && abs(y1 - y2) <= 1 || y1 == y2 && abs(x1 - x2) <= 1)
			{
				a[i][j] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		b[i] = read() ^ 1;
	}
	gaussxor();
	printf("%d\n", cnt);
	for(int i = 1; i <= n; ++i)
 	{
 		if(ans[i])
 		{
 			printf("%d %d\n", (i - 1) / 6 + 1,(i - 1) % 6 + 1);
	 	}
 	} 
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
