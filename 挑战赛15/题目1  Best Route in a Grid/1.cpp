#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 10000000;
int n;
int a[N][N], two[N][N], five[N][N];

int cntTwo(int x){
	int cnt = 0;
	while(!(x % 2)){
		x /= 2;
		cnt++;
	}
	return cnt;
}

int cntFive(int x){
	int cnt = 0;
	while(!(x % 5)){
		x /= 5;
		cnt++;
	}
	return cnt;
}

void solve(){
	int left2 = INF, left5 = INF, top2 = INF, top5 = INF;
	two[1][1] = cntTwo(a[1][1]);
	five[1][1] = cntFive(a[1][1]);
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
    		if((i + j) == 2){
    			continue;
    		}
    		left2 = INF, left5 = INF, top2 = INF, top5 = INF;
    		if(a[i][j]){
    			if(two[i][j - 1] != -1){
			    	left2 = two[i][j - 1] + cntTwo(a[i][j]);
			    	left5 = five[i][j - 1] + cntFive(a[i][j]);
			    }
			    if(two[i - 1][j] != -1){
    				top2 = two[i - 1][j] + cntTwo(a[i][j]);
    				top5 = five[i - 1][j] + cntFive(a[i][j]);
    			}
		    	two[i][j] = min(left2, top2);
		    	five[i][j] = min(left5, top5);
		    }
	    }
    }
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
    memset(two, -1, sizeof(two));
    memset(five, -1, sizeof(five));
    solve();
    printf("%d\n", min(two[n][n], five[n][n]));
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
