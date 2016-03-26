#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 100005;
const int M = 1000005;
const int INF = 0x7fffffff;

struct Node
{
    int from;
    int to;
    int val;
}f[M];

int n, m, totD, totV;
int r[N];

int find(int i)
{
    return i == r[i] ? i : r[i] = find(r[i]);
}

void add(int s, int t, int val)
{
    f[++totV].from = s;
    f[totV].to = t;
    f[totV].val = val;
}

bool cmp(const Node a,const Node b)
{
    return a.val < b.val;
}

void kruscal()
{
    totD = 0;
	totV = 1;
    for (int i = 1; i <= m; i++)
    {
    	int a = find(f[i].from);
		int b = find(f[i].to);
        if(a != b){
        	totD += f[i].val;
        	totV++;
        	r[a] = r[b];
        	if(totV == n){
	        	break;
	        }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        r[i] = i;
    }
    int from, to, val;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &from, &to, &val);
        add(from, to, val);
    }
    sort(f, f + m, cmp);
    kruscal();
    printf("%d\n", totD);
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
