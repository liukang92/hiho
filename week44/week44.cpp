#include <cstdio>
int N, A, X;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    for(scanf("%d", &N), X = 0; N--; scanf("%d", &A), X ^= A);
    puts(X ? "Alice" : "Bob");
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
