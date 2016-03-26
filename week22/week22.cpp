#include <cstdio>
using namespace std;

const int N = 100005;
int a[N];

struct StTree{
	int sum;
	int lazyTagSet;
	int lazyTagAdd;
}d[N << 2];

void build(int l,int r,int rt){
    if(l == r){
		d[rt].sum = a[l];
		return;
	}
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    d[rt].sum = d[rt << 1].sum + d[rt << 1 | 1].sum;
}

void release(int l, int m, int r, int rt){
	if(d[rt].lazyTagSet){
		d[rt << 1].lazyTagSet = d[rt].lazyTagSet;
		d[rt << 1].lazyTagAdd = 0;
		d[rt << 1].sum = (m - l + 1) * d[rt].lazyTagSet;
		d[rt << 1 | 1].lazyTagSet = d[rt].lazyTagSet;
		d[rt << 1 | 1].lazyTagAdd = 0;
		d[rt << 1 | 1].sum = (r - m) * d[rt].lazyTagSet;
		d[rt].lazyTagSet = 0;
	}
	if(d[rt].lazyTagAdd){
		d[rt << 1].lazyTagAdd += d[rt].lazyTagAdd;
		d[rt << 1].sum += (m - l + 1) * d[rt].lazyTagAdd;
		d[rt << 1 | 1].lazyTagAdd += d[rt].lazyTagAdd;
		d[rt << 1 | 1].sum += (r - m) * d[rt].lazyTagAdd;
		d[rt].lazyTagAdd = 0;
	}
}

void update(int L, int R, int type, int val, int l, int r, int rt){
    if(L <= l && r <= R){
    	if(type){
	    	d[rt].lazyTagSet = val;
	    	d[rt].lazyTagAdd = 0;
	    	d[rt].sum = (r - l + 1) * val;
	    }else{
    		d[rt].lazyTagAdd += val;
    		d[rt].sum += (r - l + 1) * val;
    	}
		return;
	}
	int m = (l + r) >> 1;
	release(l, m, r, rt);
    if(L <= m){
		update(L, R, type, val, l, m, rt << 1);
    }
	if(R > m){
    	update(L, R, type, val, m + 1, r, rt << 1 | 1);
    }
    d[rt].sum = d[rt << 1].sum + d[rt << 1 | 1].sum;
}

int query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
    	return d[rt].sum;
    }
    int m = (l + r) >> 1;
	release(l, m, r, rt);
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
    int n, m, f, x, y, z;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n + 1; ++i){
		scanf("%d", &a[i]);
	}
    build(1, n + 1, 1);  
    for(int i = 0; i < m; i++){
        scanf("%d %d %d %d", &f, &x, &y, &z);
       	update(x + 1, y + 1, f, z, 1, n + 1, 1);
       	printf("%d\n", query(1, n + 1, 1, n + 1, 1));
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
