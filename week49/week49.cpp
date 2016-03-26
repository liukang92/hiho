#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10005;
const int M = 50005;
int n, m, total;

struct Vertex{
	int head, degree;
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
	int cnt = 0;
	scan();
	for(int i = 1; i <= n; i++){
		if(v[i].degree % 2){
			cnt++;
		}
	}
	if(cnt == 0 || cnt == 2){
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
	int a, b;
	scanf("%d %d", &n, &m);
	init();
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		conn(a, b);
		conn(b, a);
	}
	puts(solve() ? "Full" : "Part");
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
