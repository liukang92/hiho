#include <cstdio>
using namespace std;

const int MAX = 1000000;
int a[20][MAX + 5];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[0][i]);
	}
	int x = 0,y;
	for(int i = 1; i <= n; i <<= 1){
		x++;	
	}
	for(int i = 1, p = 1; i < x; i++, p <<= 1){
		for(int j = 1; j + p <= n; j++){
			a[i][j] = a[i - 1][j] > a[i - 1][j + p] ? a[i - 1][j + p] : a[i - 1][j];
		}
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		int j, len, mid = (x + y) / 2;
		for(j = 0, len = 1; x + len - 1 < mid; j++, len <<= 1);
		printf("%d\n", a[j][x] > a[j][y - len + 1] ? a[j][y - len + 1] : a[j][x]);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
