#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100005;
const int M = 500005;
int t, n, m, total;
int head[N], degree[N];

struct Edge{
    int next, to;
    Edge(){}
    Edge(int to, int next):to(to), next(next){}
}e[M];

void init(){
	total = 0;
	memset(head, 0, N * sizeof(int));
	memset(degree, 0, N * sizeof(int));
	memset(e, 0, M * sizeof(Edge));
}

void conn(int u, int v){
    e[++total] = Edge(v, head[u]);
    head[u] = total;
}

void scan(){
	for(int i = 1; i <= n; i++){
		for(int u = head[i]; u; u = e[u].next){
			degree[e[u].to]++;
		}
	}
}

int solve(){
	queue<int> q;
	int cnt = 0, u;
	scan();
	for(int i = 1; i <= n; i++){
		if(!degree[i]){
			q.push(i);
			cnt++;
		}
	}
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v = head[u]; v; v = e[v].next){
			if(!(--degree[e[v].to])){
				q.push(e[v].to);
				cnt++;
			}
		}
	}
	if(cnt == n){
		return 1;
	}else{
		return 0;
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int u, v;
	scanf("%d", &t);
	while(t--){
		init();
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			conn(u, v);
		}
		puts(solve() ? "Correct" : "Wrong");
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
