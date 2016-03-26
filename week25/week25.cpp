#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
const int N = 100005;
const int M = 1000005;
const int INF = 0x7fffffff;

struct node{
	int to;
	int next;
	int val;
}f[M * 2];

int tot = 0;
int head[N];

void add(int s, int t, int val)
{
	f[++tot].to = t;
	f[tot].next = head[s];
	f[tot].val = val;
	head[s] = tot;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int nPoint, nRoad;
	scanf("%d %d", &nPoint, &nRoad);
	int start, end;
	scanf("%d %d", &start, &end);
	int from, to, val;
	for(int i = 1; i <= nRoad; i++)
	{
		scanf("%d %d %d", &from, &to, &val);
		add(from, to, val);
		add(to, from, val);
	}
	int dis[N];
	for(int i = 1; i <= nPoint; i++){
		dis[i] = INF;
	}
	dis[start] = 0;
	bool flag[N] = {false};
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		flag[p] = false;
		for(int i = head[p]; i; i = f[i].next)
		{
			int l = f[i].to;
			if(dis[l] > dis[p] + f[i].val)
			{
				dis[l] = dis[p] + f[i].val;
				if(!flag[l])
				{
					q.push(l);
					flag[l] = true;
				}
			}
		}
	}
	printf("%d\n",dis[end]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
