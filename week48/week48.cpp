#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100005;
const int M = 500005;
const int MOD = 142857;
int n, m, k, total;

struct Vertex{
	int head, degree, value;
}v[N];

struct Edge{
    int next, to;
    Edge(){}
    Edge(int to, int next):to(to), next(next){}
}e[M];

void init(){
	total = 0;
	memset(v, 0, N * sizeof(Vertex));
	memset(e, 0, M * sizeof(Edge));
}

void conn(int a, int b){
    e[++total] = Edge(b, v[a].head);
    v[a].head = total;
}

void scan(){
	for(int i = 1; i <= n; i++){
		for(int a = v[i].head; a; a = e[a].next){
			v[e[a].to].degree++;
		}
	}
}

int solve(){
	queue<int> q;
	int cnt = 0, a;
	scan();
	for(int i = 1; i <= n; i++){
		if(!v[i].degree){
			q.push(i);
		}
	}
	while(!q.empty()){
		a = q.front();
		cnt = (cnt + v[a].value) % MOD;
		q.pop();
		for(int b = v[a].head; b; b = e[b].next){
			v[e[b].to].value += v[a].value % MOD;
			if(!(--v[e[b].to].degree)){
				q.push(e[b].to);
			}
		}
	}
	return cnt;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int a, b;
	scanf("%d %d %d", &n, &m, &k);
	init();
	for(int i = 0; i < k; i++){
		scanf("%d", &a);
		v[a].value = 1;
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		conn(a, b);
	}
	printf("%d\n", solve());
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
