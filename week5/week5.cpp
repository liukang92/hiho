#include <iostream>
#include <cstdio>
using namespace std;

int a[205];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, x, last, cur;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
    	last = 0;
    	for(int j = 0; j < i; ++j){
	    	scanf("%d", &x);
			cur = a[j];
			a[j] = (cur > last ? cur : last) + x;
			last = cur;
	    }
    }
    x = 0;
    for(int i = 0; i < n; ++i){
    	if(a[i] > x){
   	 		x = a[i];	
	    }
    }
    printf("%d\n", x);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
