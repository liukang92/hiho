#include <iostream>
#include <cstdio>
using namespace std;

const int maxLen = 1 << 20;
char s[maxLen];
int a[maxLen][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m, index, cnt, flag;
	char x;
	scanf("%d", &n);
	while(n--){ 
		scanf("%d", &m);
		scanf("%s", s);
		x = s[0];
		index = 0;
		cnt = 1;
		for(int i = 1; i < m; i++){
			if(x != s[i]){
				a[index][0] = x;
				a[index++][1] = cnt;
				x = s[i];
				cnt = 1;
			}else{
				cnt++;
			}
		}
		a[index][0] = x;
		a[index++][1] = cnt;
				
		flag = 0;
		for(int i = 0; i < index - 2; i++){
			if((a[i][0] + 1) == a[i + 1][0] && (a[i + 1][0] + 1) == a[i + 2][0]
				&& a[i][1] >= a[i + 1][1] && a[i + 2][1] >= a[i + 1][1]){
				flag = 1;
				break;
			} 
		} 
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
