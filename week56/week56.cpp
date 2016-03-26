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
	while(t > 47 && t < 58) x = (x << 1) + (x << 3) + t - 48, t = getchar();
	return x * f;
}

const int maxn = 505;
const int maxm = 1005;
const double eps = 1e-6;

int n, m;
double a[maxm][maxn], b[maxm];
int ans[maxn];

bool zero(double x)
{
	return fabs(x) < eps;
}
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
int gauss()
{
	for(int i = 1; i <= n; ++i)
	{
		int r = 0;
		for(int j = i; j <= m; ++j)
		{
			if(fabs(a[j][i]) > fabs(a[r][i]))
			{
				r = j;
			} 
		}
		if(!r)
		{
			return 2;
		}
		swapRow(i, r);
		for(int j = i + 1; j <= m; ++j)
		{
			double f = 1.0 * a[j][i] / a[i][i];
			for(int k = 1; k <= n; ++k)
			{
				a[j][k] -= a[i][k] * f;
			}	
			b[j] -= b[i] * f;
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		bool flag = 1;
		for(int j = 1; j <= n; ++j)
		{
			if(!zero(a[i][j])) 
			{
				flag = 0;
				break;
			}
		}
		if(flag && zero(b[i]))
		{
			flag = 0;
		} 
		if(flag)
		{
			return 0;	
		} 
	}
	for(int i = n; i >= 1; --i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			b[i] -= a[i][j] * ans[j];
			a[i][j] = 0;
		}
		ans[i] = b[i] / a[i][i] + 0.5;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	n = read(), m = read();
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
			a[i][j] = read();
		b[i] = read();
	}
	int flag = gauss();
	if(flag == 1) for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	else if(flag == 0) puts("No solutions");
	else puts("Many solutions");
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
