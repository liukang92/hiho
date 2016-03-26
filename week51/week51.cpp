#include <cstdio>
#include <cstring>
using namespace std;

const int N = 15;
const int M = 1 << (N - 1) + 5;
int n, m, total;
int map[M][2], res[M];

void dfs(int v){
	int u;
	for(int i = 0; i < 2; i++){
        if(map[v][i] != -1){
        	u = map[v][i];
        	map[v][i] = -1;
            dfs(u);
        }
    }
    res[++total] = v;//³öÕ»Ë³Ðò 
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    if (n == 1)
    {
        printf("01\n");
        return 0;
    }
    m = 1 << (n - 1);
    int j;
    for (int i = 0; i < m; i++){
  	 	j = (i << 1) & (m - 1);
        map[i][0] = j;
        map[i][1] = j + 1;
    }
    dfs(0);
    for (int i = total; i >= 2; i--){
        printf("%d", res[i] & 1);
    }
    printf("\n");
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
