#include <cstdio>

const int N = 100005;

struct {
	int next;
	int to;
} tree_node[N];

int header[N], max_length;

int dfs(int node) {
	int first = 0, second = 0;
	int p = header[node];
	int length = 0;
	while(p) {
		length = dfs(tree_node[p].to) + 1;
		if(length > first) {
			second = first;
			first = length;
		}
		else if(length > second){
			second = length;
		}
		p = tree_node[p].next;
	}
	if(max_length < first + second){
		max_length = first + second;
	}
	return first;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int from, to, n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &from, &to);
		tree_node[i].to = to;
		tree_node[i].next = header[from];
		header[from] = i;
	}
	dfs(1);
	printf("%d\n", max_length);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
