#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
const int M = 20005;
int sg[M];

void getSg(int x){
	int a[M];
	int j;
	for(int i = 1; i < x; i++){
		memset(a, 0, M * sizeof(int));
		for(j = 1; j < i; j++){
			a[sg[j]] = 1;
			a[sg[i - j] ^ sg[j]] = 1;
		}
		j = 1;
		while(a[j]){
			j++;
		}
		sg[i] = j;
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int n, x, ans;
	getSg(20000);
    for(scanf("%d", &n), ans = 0; n--; scanf("%d", &x), ans ^= sg[x]);
    printf("%s\n", ans ? "Alice" : "Bob");
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
