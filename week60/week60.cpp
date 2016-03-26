#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2105;
char a[N], b[N]; 
int len1, len2;
int f[N][N], dp[N][N][2];

void getF(){
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(a[i] == b[j]){
				f[i][j] = f[i - 1][j - 1] + 1;
			}
		}
	}
}

void solve(){
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
			if(f[i][j] >= 3){
				dp[i][j][1] = max(dp[i - 1][j - 1][1] + 1, dp[i - 3][j - 3][0] + 3);
				dp[i][j][0] = max(dp[i][j][0], dp[i][j][1]);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", a + 1, b + 1);
	a[0] = b[0] = '$';
	len1 = strlen(a);
	len2 = strlen(b);
	getF();
	solve();
	printf("%d\n", dp[len1 - 1][len2 - 1][0]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
