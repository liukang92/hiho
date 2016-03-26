#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100005;
int a[N << 1];
int b[N][2];
int ret;
map<int, int> H;

struct StTree{
	int last;
	int lazyTag;
}d[N << 2];

void build(int l, int r, int rt){
    if(l == r){
    	d[rt].lazyTag = -1;
		return;
	}
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    d[rt].lazyTag = -1;
}

void update(int L, int R, int val, int l, int r, int rt){
    if(L <= l && r <= R){
		d[rt].lazyTag = val;
		d[rt].last = val;
		return;
	}
	int m = (l + r) >> 1;
	if(d[rt].lazyTag != -1){
		d[rt << 1].lazyTag = d[rt].lazyTag;
		d[rt << 1].last = d[rt].lazyTag;
		d[rt << 1 | 1].lazyTag = d[rt].lazyTag;
		d[rt << 1 | 1].last = d[rt].lazyTag;
		d[rt].lazyTag = -1;
	}
    
    if(L <= m){
		update(L, R, val, l, m, rt << 1);
    }
	if(R > m){
    	update(L, R, val, m + 1, r, rt << 1 | 1);
    }
    if(d[rt << 1].last == d[rt << 1 | 1].last){
    	d[rt].last = d[rt << 1].last;
    }else{
    	d[rt].last = 0;
    }
}

void query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
    	if(d[rt].last){
	    	if(!H[d[rt].last]){
	    		H[d[rt].last] = ++ret;
	    	}
			return;
	    }
	    if(l == r){
    		return;
    	}
    }
	int m = (l + r) >> 1;
//	if(d[rt].lazyTag != -1){
//		d[rt << 1].lazyTag = d[rt].lazyTag;
//		d[rt << 1].last = d[rt].lazyTag;
//		d[rt << 1 | 1].lazyTag = d[rt].lazyTag;
//		d[rt << 1 | 1].last = d[rt].lazyTag;
//		d[rt].lazyTag = -1;
//	}
	
    if(L <= m){
    	query(L, R, l, m, rt << 1);
    }
    if(R > m){
  		query(L, R, m + 1, r, rt << 1 | 1);
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	int x, y, z, q = 0, f;
	scanf("%d %d", &n, &m);
    for(int i = 1, j = 1; i <= n; i++, j += 2){
    	scanf("%d %d", &b[i][0], &b[i][1]);
    	a[j] = b[i][0];
    	a[j + 1] = b[i][1];
    }
	std::sort(a + 1, a + 1 + 2 * n);
	for(int i = 1; i <= 2 * n; i++){
		if(!H[a[i]]){
			H[a[i]] = ++q;
		}
	}
    build(1, q - 1, 1);
    for(int i = 1; i <= n; i++){
    	//printf("%d %d\n", H[b[i][0]], H[b[i][1]] - 1);
   		update(H[b[i][0]], H[b[i][1]] - 1, i, 1, q - 1, 1);
    }
    H.clear();
    query(1, q - 1, 1, q - 1, 1);
    printf("%d\n", ret);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
