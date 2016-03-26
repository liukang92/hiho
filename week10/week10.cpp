#include <cstdio>

char pre[30], in[30];
void postorder(int i, int j, int k) {
	//i前序起始点，j中序起始点，k中序终止点 
	int t;
	if(!in[j] || j >= k)
		return;
	for(t = j; pre[i] != in[t]; t++);
	postorder(i + 1, j, t);
	postorder(i + (t - j) + 1, t + 1, k);
	printf("%c", pre[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%s%s", pre, in);
	postorder(0, 0, 26);
	printf("\n");
	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
