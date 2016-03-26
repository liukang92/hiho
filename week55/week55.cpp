#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20005;
const int M = 100005;
int n, m, total, top = -1, gCnt;
int stack[M << 1]; 

struct Vertex{
    int head, visit, dfn, low;
}v[N];

struct Edge{
    int next, to, group;
    Edge(){}
    Edge(int to, int next):to(to), next(next), group(0){}
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
    for (int a = v[c].head, childCnt = 1; a; a = e[a].next, childCnt++){
    	if(e[a].group){
	    	continue;
	    }
    	if(!v[e[a].to].visit){
    		stack[++top] = (a + 1) >> 1;
    		dfs(c, e[a].to);
			v[c].low = min(v[c].low, v[e[a].to].low);
			if(!p && childCnt > 1 || p && v[c].dfn <= v[e[a].to].low){
				gCnt++;
		    	int id = (a + 1) >> 1;
		    	for(int i = top; stack[i] != (a + 1) >> 1; i--){
			    	id = min(id, stack[i]);
			    }
			    do{
			    	e[stack[top] << 1].group = id;
		    		e[(stack[top] << 1) - 1].group = id;
		    	}while(stack[top--] != (a + 1) >> 1);
		    }
        }else if(e[a].to != p){
        	stack[++top] = (a + 1) >> 1;
        	v[c].low = min(v[c].low, v[e[a].to].dfn);
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
    for (int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        conn(a, b);
        conn(b, a);
    }
    total = 0;
    dfs(0, 1);
    int id = stack[0];
    gCnt++;
	for(int i = top; i > 0; i--){
		id = min(id, stack[i]);
	}
    while(top > -1){
		e[stack[top] << 1].group = id;
		e[(stack[top--] << 1) - 1].group = id;
	}
	printf("%d\n", gCnt);
    for(int i = 1; i <= (m << 1); i += 2){
   		printf("%d ", e[i].group);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
	return 0; 
}
