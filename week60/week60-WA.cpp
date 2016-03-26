#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2105;
char a[N], b[N]; 
int len1, len2;
int f[N][N], dp[N][N];

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
	int m;
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(f[i][j] >= 3){
				m = max(3, f[i][j] - 2);
				for(int k = m; k <= f[i][j]; k++){
					dp[i][j] = max(dp[i][j], dp[i - k][j - k] + k);
				}
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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
	printf("%d\n", dp[len1 - 1][len2 - 1]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
