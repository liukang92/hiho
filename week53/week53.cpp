#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20005;
const int M = 100005;
int n, m, total, top = -1, gCnt;
int stack[N]; 

struct Vertex{
    int head, visit, dfn, low, group;
}v[N];

struct Edge{
    int next, to;
    Edge(){}
    Edge(int to, int next):to(to), next(next){}
}e[M << 1];

void init(){
    total = 0;
    memset(v, 0, N * sizeof(Vertex));
    memset(e, 0, M * sizeof(Edge));
}

void conn(int a, int b){
    e[++total] = Edge(b, v[a].head);
    v[a].head = total;
}

void dfs(int p, int c){
	v[c].dfn = v[c].low = ++total;
	v[c].visit = 1;
	stack[++top] = c;
    for (int a = v[c].head, childCnt = 1; a; a = e[a].next, childCnt++){
    	if (!v[e[a].to].visit){
    		dfs(c, e[a].to);
			v[c].low = min(v[c].low, v[e[a].to].low);
        }else if(e[a].to != p){
        	v[c].low = min(v[c].low, v[e[a].to].dfn);
        }
    }
    if(v[c].dfn == v[c].low){
    	int id = c;
    	for(int i = top; stack[i] != c; i--){
	    	id = min(id, stack[i]);
	    }
	    while(stack[top] != c){
    		v[stack[top--]].group = id;
    	}
    	v[c].group = id;
    	top--;
    	gCnt++;
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
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        conn(a, b);
        conn(b, a);
    }
    total = 0;
    dfs(0, 1);
    printf("%d\n", gCnt);
    for(int i = 1; i <= n; i++){
   		printf("%d ", v[i].group);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
	return 0; 
}
