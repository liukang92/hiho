#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 10100, M = 40100;
struct Edge{
    int to, nx;
    Edge(){}
    Edge(int to, int nx):to(to), nx(nx){}
}e[M * 2];
int tot, hd[N];

void clear(int n){
    tot = 0;
    memset(hd, 0, sizeof(hd[0]) * (n + 1));
}

void conn(int u, int v){
    e[++tot] = Edge(v, hd[u]);
    hd[u] = tot;
}

char col[N];
int n, m;
bool dfs(int u){
    int v;
    for(int i = hd[u]; i; i = e[i].nx){
        v = e[i].to;
        if(col[v] == col[u]) return false;
        if(!col[v]){
            col[v] = (col[u] == 1 ? 2 : 1);
            if(!dfs(v))return false;
        }
    }
    return true;
}
bool judgeBipartite(){
    memset(col, 0, sizeof(col[0]) * (n + 1));
    for(int u = 1; u <= n; ++u){
    	if(!col[u]){
   	 		col[u] = 1;
        	if(!dfs(u))return false;
    	}
    }	
    return true;
}
void solve(){
    int u, v;
    scanf("%d%d", &n, &m);
    clear(n);
    while(m--){
        scanf("%d%d", &u, &v);
        conn(u, v);
        conn(v, u);
    }
    if(judgeBipartite())puts("Correct");
    else puts("Wrong");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    int t;
    scanf("%d", &t);
    while(t--)solve();
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
