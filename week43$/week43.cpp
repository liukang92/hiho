#include <cstdio>
#include <cstring>
#define int64 long long
#define MOD 12357

const int N = (1 << 7) + 5;

int k; 
int64 n;
int t[N][N];

void dfs(int x, int y, int col, int **a){
	if(col == k){
		a[y][x] = 1;
		return;
	}
	dfs(x << 1, (y << 1) + 1, col + 1, a);
	dfs((x << 1) + 1, y << 1, col + 1, a);
	if(col + 2 <= k){
		dfs((x << 2) + 3, (y << 2) + 3, col + 2, a);
	}
}

void p(int **a, int **b, int **c, int dim){
	int sum = 0;
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			sum = 0;
			for(int k = 0; k < dim; k++){
				sum += a[i][k] * b[k][j];
			}
			t[i][j] = sum % MOD;
		}
	}
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			c[i][j] = t[i][j];
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	scanf("%d %d", &k, &n);
	int dim = 1 << k;
	int **r = new int*[dim];
	int **a = new int*[dim];
	for(int i = 0; i < dim; i++){
		r[i] = new int[dim];
		a[i] = new int[dim];
		memset(r[i], 0, dim * sizeof(int));
		memset(a[i], 0, dim * sizeof(int));
		r[i][i] = 1;
	}
	
	dfs(0, 0, 0, a);
	while(n){
		if(n & 1){
			p(r, a, r, dim);
		}
		p(a, a, a, dim);
		n >>= 1;
	}
	printf("%d\n", r[dim - 1][dim - 1]);
	for(int i = 0; i < dim; i++){
		delete[] r[i], a[i]; 
	}
	delete[] r, a; 
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
