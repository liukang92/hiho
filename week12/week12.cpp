#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100;
const int M = 100;
const int NN = 1000;

struct {
	int parent;
	int next;
	int child;
	int value;
} tree_node[NN + 5];

int dp[N + 5][M + 5];
int n, m;

void f(int node) {
	dp[node][0] = 0;
	dp[node][1] = tree_node[node].value;
	for(int i = tree_node[node].child; i; i = tree_node[i].next){
		for(int j = m; j >= 2; j--){
			for(int k = 1; k <= (j - 1); k++){
				if(dp[node][j - k] && dp[i][k]){
					dp[node][j] = max(dp[node][j], dp[node][j - k] + dp[i][k]);
				}
			}
		}
	}
}

int lrd(int node){
	if(tree_node[node].child){
		lrd(tree_node[node].child);
	}
	if(tree_node[node].next){
		lrd(tree_node[node].next);
	}
	f(node);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int from, to;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tree_node[i].value);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &from, &to);
		tree_node[to].parent = from;
		tree_node[to].next = tree_node[from].child;
		tree_node[from].child = to;
	}
	lrd(1);
	printf("%d\n", dp[1][m]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
