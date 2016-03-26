#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 20005;
const int M = 100005;
int n, m, total, top = -1, res;
int stack[N], edge[M][2]; 

struct Vertex{
    int head, value, max, visit, dfn, low, group, stack, in;
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

void tarjan(int c){
	v[c].dfn = v[c].low = ++total;
	v[c].visit = 1;
	stack[++top] = c;
	v[c].stack = 1;
    for (int a = v[c].head; a; a = e[a].next){
    	if (!v[e[a].to].visit){
    		tarjan(e[a].to);
			v[c].low = min(v[c].low, v[e[a].to].low);
        }else if(v[e[a].to].stack){
        	v[c].low = min(v[c].low, v[e[a].to].dfn);
        }
    }
    if(v[c].dfn == v[c].low){	
   		int id = c;
   		int sum = v[c].value;
    	for(int i = top; stack[i] != c; i--){
	    	id = min(id, stack[i]);
	    	sum += v[stack[i]].value;
	    }
	    while(stack[top] != c){
    		v[stack[top--]].group = id;
    	}
    	v[stack[top]].value = sum;
    	v[stack[top--]].group = id;
    }
}

void scan(){
	for(int i = 1; i <= n; i++){
		for(int u = v[i].head; u; u = e[u].next){
			v[e[u].to].in++;
		}
	}
}

void solve(){
	for(int i = 1; i <= n; i++){
		v[i].head = 0;
	}
	for(int i = 1; i <= m; i++){
		if(v[edge[i][0]].group != v[edge[i][1]].group){
			conn(v[edge[i][0]].group, v[edge[i][1]].group);
		}
	}
	
	queue<int> q;
	int a;
	scan();
	q.push(1);
	v[1].max = v[1].value;
	while(!q.empty()){
		a = q.front();
		q.pop();
		if(v[a].max > res){
			res = v[a].max;
		}
		for(int b = v[a].head; b; b = e[b].next){
			if((v[a].max + v[e[b].to].value) > v[e[b].to].max){
					v[e[b].to].max = v[a].max + v[e[b].to].value;
			}
			if(!(--v[e[b].to].in)){
				q.push(e[b].to);
			}
		}
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
    for (int i = 1; i <= n; i++){
        scanf("%d", &v[i].value);
    }
    for (int i = 1; i <= m; i++){
        scanf("%d %d", &edge[i][0], &edge[i][1]);
        conn(edge[i][0], edge[i][1]);
    }
    total = 0;
    tarjan(1);
    total = 0;
    solve();
    printf("%d\n", res);
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
	return 0; 
}
