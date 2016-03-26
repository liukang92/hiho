#include<cstdio>
char ch[10005];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    int ans = 0;
	int n;
	scanf("%d", &n);
	scanf("%s", ch);
	for(int i = 0; i < n; i++){
		if(ch[i] == 'H'){
			ans ^= (i + 1);
		}
	}
	printf("%s\n", ans ? "Alice" : "Bob");
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
