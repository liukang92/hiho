#include <cstdio>
#include <string.h>

using namespace std;
const int N = 1005, M = 5005;
struct Edge{
    int to, nx;
    Edge(){}
    Edge(int to, int nx):to(to), nx(nx){}
}e[M * 2];
int n, m, tot, hd[N], used[N], couple[N];

void conn(int u, int v){
    e[++tot] = Edge(v, hd[u]);
    hd[u] = tot;
}

bool find(int x){
    for (int i = hd[x], j; i; i = e[i].nx){
    	j = e[i].to;
        if(!used[j]){
            used[j] = 1;  
            if (couple[j] == 0 || find(couple[j])){   
                couple[j] = x; 
                couple[x] = j; 
                return true;  
            }  
        }  
    }  
    return false;  
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int u, v;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
    	scanf("%d %d", &u, &v);
    	conn(u, v);
    	conn(v, u);
    }
    tot = 0;
    for(int i = 1; i <= n; i++){
    	if(!couple[i]){
   			memset(used, 0, sizeof(used));
    		if(find(i)){
  	 			tot++;	
  		 	}
	    }
    }
    printf("%d\n%d\n", tot, n - tot);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
