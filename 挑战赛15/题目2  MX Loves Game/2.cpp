#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 305;
int n;
int a[N][N], b[N][N], c[N][N];

void solve(){
	
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
	    	scanf("%d", &a[i][j]);
	    }
    }
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
	    	scanf("%d", &b[i][j]);
	    }
    }
    
	for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
	    	c[i][j] = a[i][j] - b[i][j];
	    }
    }

    solve();
    //printf("%d\n", min(two[n][n], five[n][n]));
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
