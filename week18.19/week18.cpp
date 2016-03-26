#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100005;
int a[N], d[N << 1];

void build(int l,int r,int rt){
    if(l == r){
		d[rt] = a[l];
		return;
	}
    int w = (l + r) >> 1;
    build(l, w, rt << 1);
    build(w + 1, r, rt << 1 | 1);
    d[rt] = min(d[rt << 1], d[rt << 1 | 1]);
}

void update(int p, int val, int l, int r, int rt){
    if(p == l && l == r){
		d[rt] = val;
		return;
	}
    int w = (l + r) >> 1;
    if(p <= w){
		update(p, val, l, w, rt << 1);
    }else{
    	update(p, val, w + 1, r, rt << 1 | 1);
    }
    d[rt] = min(d[rt << 1], d[rt << 1 | 1]);
}

int query(int L, int R, int l, int r, int rt){
    if(L <= l && r <= R){
    	return d[rt];
    }
	int w = (l + r) >> 1;
    int ret = N;
    if(L <= w){
    	ret = min(ret, query(L, R, l, w, rt << 1));
    }
    if(R > w){
    	ret = min(ret, query(L, R, w + 1, r, rt << 1 | 1));
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
    build(1, n, 1);
    cin >> q;
    for(int i = 0, c, p, w; i < q; i++){
        scanf("%d %d %d", &c, &p, &w);
        if(c){
        	update(p, w, 1, n, 1);
        }else{
        	printf("%d\n", query(p, w, 1, n, 1));	
        }
    }	
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
