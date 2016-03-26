#include <cstdio>
#include <cstring>
#define N 100100
int ct = 1;
int nm = 1;
char s[N][60];
struct node{
	int num;
	int next[70];
};
node e[30*N];
struct tree{
	int to, next;
	int index;
}rt[N], qt[N*2];
int rh[N], qh[N];
int getnum(char *t){
	int s = 0, i;
	for(i = 0; t[i]; i++){
		int x = t[i] - 'A';
		if(e[s].next[x]){
			s = e[s].next[x];
		}else{
			e[s].next[x] = ct++;
			s = e[s].next[x];
		}
	}
	if(e[s].num == 0){
		e[s].num = nm++;
	}
	return e[s].num;
}
int p[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
bool vis[N];
void dfs(int x){
	vis[x]=1;
	p[x]=x;
	int v;
	for(int i=rh[x];i;i=rt[i].next){
		v=rt[i].to;
		dfs(v);
		p[v]=x;
	}
	for(int i=qh[x];i;i=qt[i].next){
		v=qt[i].to;
		if(vis[v]){
			qt[i].index=find(v);
			qt[i^1].index=qt[i].index;
		}
	}
}
bool id[N];
bool ex[N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
	ct = 1;
	char fa[60], son[60];
	int u, v;
	int rc = 1, qc = 2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %s", fa, son);
		u = getnum(fa);
		v = getnum(son);
		if(!ex[u])strcpy(s[u], fa), ex[u] = 1;
		if(!ex[v])strcpy(s[v], son), ex[v] = 1;
        rt[rc].to = v;
		rt[rc].next = rh[u];
		rh[u] = rc++;
		id[v] = 1;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%s %s", fa, son);
		u = getnum(fa);
		v = getnum(son);
		qt[qc].to = v;
		qt[qc].next = qh[u];
		qh[u] = qc++;
		qt[qc].to = u;
		qt[qc].next = qh[v];
		qh[v] = qc++;
	}
	for(int i = 1; i <= n; i++){
		if(!id[i]){
	 		dfs(i);
	 	}
		break;
	}
	for(int i = 2; i < 2 * m + 2; i += 2){
		puts(s[qt[i].index]);
	} 	
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
