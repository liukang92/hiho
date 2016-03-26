#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int d[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y;
	scanf("%d %d", &n, &m); 
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		for(int j = m; j >= x; j--){
  			d[j] = max(d[j], d[j - x] + y);
		} 
	}	
	printf("%d\n", d[m]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
