#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N = 10005;
const int M = 100005; 

struct Edge{
	int to, next, val;
	Edge(){}
    Edge(int to, int next, int val) : to(to), next(next), val(val){}
}e[M << 1];
int n, m, k, t, tot;
int head[N], vis[N];

void add(int from, int to, int val){
	e[++tot] = Edge(to, head[from], val);
	head[from] = tot;
}

bool f(int x){
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		if(u == t){
			return true;
		}
		if(vis[u] == k){
			continue;
		}
		for(int i = head[u]; i; i = e[i].next){
			v = e[i].to;
			if(vis[v] || e[i].val > x){
				continue;
			}
			vis[v] = vis[u] + 1;
			q.push(v);
		}
	}
	return false;
}

int solve(int l, int r){
	while(l < r){
		int mid = (l + r) >> 1;
		if(f(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return l; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    scanf("%d %d %d %d",&n, &m, &k, &t);
    int from, to, val, max = 0;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d %d", &from, &to, &val);
        add(from, to, val);
        add(to, from, val);
        if(val > max){
        	max = val;
        }
    }
    printf("%d\n", solve(1, max));
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
