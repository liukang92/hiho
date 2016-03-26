#include <cstdio>
#define MOD 12357
#define int64 long long
int64 t[8][8];
void p(int64 a[][8], int64 b[][8], int64 c[][8]){
	int sum = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			sum = 0;
			for(int k = 0; k < 8; k++){
				sum += a[i][k] * b[k][j];
			}
			t[i][j] = sum % MOD;
		}
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			c[i][j] = t[i][j];
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int64 r[8][8] = {1, 0, 0, 0, 0, 0, 0, 0,
					 0, 1, 0, 0, 0, 0, 0, 0,
					 0, 0, 1, 0, 0, 0, 0, 0,
					 0, 0, 0, 1, 0, 0, 0, 0,
					 0, 0, 0, 0, 1, 0, 0, 0,
					 0, 0, 0, 0, 0, 1, 0, 0,
					 0, 0, 0, 0, 0, 0, 1, 0,
					 0, 0, 0, 0, 0, 0, 0, 1};
	int64 a[8][8] = {0, 0, 0, 0, 0, 0, 0, 1,
					 0, 0, 0, 0, 0, 0, 1, 0,
					 0, 0, 0, 0, 0, 1, 0, 0,
					 0, 0, 0, 0, 1, 0, 0, 1,
					 0, 0, 0, 1, 0, 0, 0, 0,
					 0, 0, 1, 0, 0, 0, 0, 0,
					 0, 1, 0, 0, 0, 0, 0, 1,
					 1, 0, 0, 1, 0, 0, 1, 0};
	int n;
	scanf("%d", &n);
	while(n){
		if(n & 1){
			p(r, a, r);
		}
		p(a, a, a);
		n >>= 1;
	}
	printf("%lld\n", r[7][7]);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
