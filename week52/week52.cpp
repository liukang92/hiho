#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20005;
const int M = 100005;
int n, m, total, vCnt, eCnt;
int **eRes; 

struct Vertex{
    int head, visit, dfn, low, cut;
}v[N];

struct Edge{
    int next, to;
    Edge(){}
    Edge(int to, int next):to(to), next(next){}
}e[M << 1];

bool cmp(int *p, int *q){
	if(p[0] == q[0]){ 
		return p[1] < q[1];
	}else{
		return p[0] < q[0];
	}
}

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
    	if (!v[e[a].to].visit){
    		dfs(c, e[a].to);
			v[c].low = min(v[c].low, v[e[a].to].low);
			if(!p && childCnt > 1 || p && v[c].dfn <= v[e[a].to].low){
				v[c].cut = 1;
				vCnt++;
			}
			if(v[c].dfn < v[e[a].to].low){
				eRes[eCnt] = new int[2];
				if(c < e[a].to){
					eRes[eCnt][0] = c;
					eRes[eCnt++][1] = e[a].to;	
				}else{
					eRes[eCnt][0] = e[a].to;
					eRes[eCnt++][1] = c;	
				}
			}
        }else if(e[a].to != p){
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
    eRes = new int*[M];
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        conn(a, b);
        conn(b, a);
    }
    total = 0;
    dfs(0, 1);
    sort(eRes, eRes + eCnt, cmp);
    if(!vCnt){
    	printf("Null");
    }else{
    	for(int i = 1; i <= n; i++){
    		if(v[i].cut){
		    	printf("%d ", i);
		    }
	    }
    }
    printf("\n");
    for(int i = 0; i < eCnt; i++){
   		printf("%d %d\n", eRes[i][0], eRes[i][1]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
	return 0; 
}
