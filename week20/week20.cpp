#include <cstdio>
using namespace std;

const int N = 100005;
int a[N];

struct StTree{
	int sum;
	int lazyTag;
}d[N << 2];

void build(int l,int r,int rt){
    if(l == r){
    	d[rt].lazyTag = -1;
		d[rt].sum = a[l];
		return;
	}
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    d[rt].lazyTag = -1;
    d[rt].sum = d[rt << 1].sum + d[rt << 1 | 1].sum;
}

void update(int L, int R, int val, int l, int r, int rt){
    if(L <= l && r <= R){
		d[rt].lazyTag = val;
		d[rt].sum = (r - l + 1) * val;
		return;
	}
	int m = (l + r) >> 1;
	if(d[rt].lazyTag != -1){
		d[rt << 1].lazyTag = d[rt].lazyTag;
		d[rt << 1].sum = (m - l + 1) * d[rt].lazyTag;
		d[rt << 1 | 1].lazyTag = d[rt].lazyTag;
		d[rt << 1 | 1].sum = (r - m) * d[rt].lazyTag;
		d[rt].lazyTag = -1;
	}
    
    if(L <= m){
		update(L, R, val, l, m, rt << 1);
    }
	if(R > m){
    	update(L, R, val, m + 1, r, rt << 1 | 1);
    }
    d[rt].sum = d[rt << 1].sum + d[rt << 1 | 1].sum;
}

int query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
    	return d[rt].sum;
    }
	int m = (l + r) >> 1;
	if(d[rt].lazyTag != -1){
		d[rt << 1].lazyTag = d[rt].lazyTag;
		d[rt << 1].sum = (m - l + 1) * d[rt].lazyTag;
		d[rt << 1 | 1].lazyTag = d[rt].lazyTag;
		d[rt << 1 | 1].sum = (r - m) * d[rt].lazyTag;
		d[rt].lazyTag = -1;
	}
	
    int left = 0, right = 0;
    if(L <= m){
    	left = query(L, R, l, m, rt << 1);
    }
    if(R > m){
    	right = query(L, R, m + 1, r, rt << 1 | 1);
    }
    return left + right;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n, q, f, x, y, z;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
    build(1, n, 1);
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &f);
        if(f){
        	scanf("%d %d %d", &x, &y, &z);
        	update(x, y, z, 1, n, 1);
        }else{
        	scanf("%d %d", &x, &y);
        	printf("%d\n", query(x, y, 1, n, 1));	
        }
    }	
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
