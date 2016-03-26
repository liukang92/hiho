#include <cstdio>
#define N 100000

char a[N], b[N], c[N];

#define rep(i,n) for(int i = 0; i < n; i++)
 
int go(int x, int n) {
	int f = 1;
	b[0] = x;
	b[1] = a[0] - b[0];
	if(b[1] < 0 || b[1] > 1){
		f = 0;
	}
	for(int i = 1; i < n; i++) {
		b[i + 1] = a[i] - b[i] - b[i - 1];
		if(b[i + 1] < 0 || b[i + 1] > 1){
			f = 0;
			break;
		}
	}
	if(f && (b[n] != 0)){
		f = 0;	
	}
	return f;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    int n, t, x, y, z, f, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, n) {
			scanf("%d", &x);
			a[i] = x; 
			b[i] = 0; 
			c[i] = 0;
		}
		char mask = 0;
		if(go(0, n)) {
			mask++;
			rep(i, n) c[i] += b[i];
		}
		if(go(1, n)) {
			mask++;
			rep(i, n) c[i] += b[i];
		}
		r = 0;
		rep(i, n) if(c[i] == mask) r++;
		printf("%d ",r); rep(i,n) if(c[i] == mask) printf("%d ",i + 1); printf("\n");
		r = 0;
		rep(i,n) if(c[i] == 0) r++;
		printf("%d ",r); rep(i,n) if(c[i] == 0) printf("%d ",i + 1); printf("\n");
	}
	return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
