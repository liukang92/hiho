#include <cstdio>
#define MOD 19999997
#define int64 long long
int64 t[2][2];
void p(int64 a[][2], int64 b[][2], int64 c[][2]){
	t[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	t[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	t[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	t[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	c[0][0] = t[0][0];
	c[0][1] = t[0][1];
	c[1][0] = t[1][0];
	c[1][1] = t[1][1];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int64 r[2][2] = {1, 0, 0, 1}, a[2][2] = {0, 1, 1, 1};
	int n;
	scanf("%d", &n);
	while(n){
		if(n & 1){
			p(r, a, r);
		}
		p(a, a, a);
		n >>= 1;
	}
	printf("%lld\n", r[1][1]);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
