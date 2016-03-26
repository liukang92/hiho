#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int const N = 1e5 + 10, M = 1e6 + 10, INF = 1e9;
typedef pair<int, int> pii;
int u, v, w, cnt, h[N], n, m, s, t, dis[N], isIn[N];
struct Edge {
    int t, n, l;
} g[M << 1];

void insert(int f, int t, int l) {
    g[cnt].t = t;
    g[cnt].l = l;
    g[cnt].n = h[f];
    h[f] = cnt++;
    g[cnt].t = f;
    g[cnt].l = l;
    g[cnt].n = h[t];
    h[t] = cnt++;
}

bool relax(int &a, int b) { return a > b ? (a = b, true) : false; }

int dijkstra(int s, int t) {
    priority_queue<pii> que;
    int d;
	fill(dis, dis + n + 1, INF);
	que.push(pii(dis[s] = 0, s));
    while (!que.empty()){
        s = que.top().second;
		d = -que.top().first;
		que.pop();
		isIn[s] = 1;
        if (d > dis[s]){
        	continue;
        }
        for (int i = h[s], t; ~i; i = g[i].n){
        	if (!isIn[i] && relax(dis[t = g[i].t], d + g[i].l)){
            	que.push(pii(-dis[t], t));
            }
        }
    }
    return dis[t];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m >> s >> t;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        insert(u, v, w);
    }
    cout << dijkstra(s, t) << endl;
    return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
