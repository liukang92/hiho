#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50005;

struct sTreeNode {
    int left, right;
    int same, add;
    int delta, inc;
    int lch, rch;
} tree[MAXN << 2];

void createTree(int rt, int left, int right) {
    tree[rt].left = left, tree[rt].right = right;
    tree[rt].delta = tree[rt].step = 0;
    tree[rt].add = 0;

    if (left == right) {    // 叶子节点
        tree[rt].base = str[ left ] - 'A';
        tree[rt].lch = tree[rt].rch = 0;
        return ;
    }

    // 非叶子节点
    tree[rt].base = -1;
    tree[rt].lch = rt * 2, tree[rt].rch = rt * 2 + 1;

    int mid = (tree[rt].left + tree[rt].right) >> 1;
    createTree(tree[rt].lch, left, mid);
    createTree(tree[rt].rch, mid + 1, right);
    return ;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", a + 1, b + 1);
	a[0] = b[0] = '$';
	len1 = strlen(a);
	len2 = strlen(b);
	getF();
	solve();
	printf("%d\n", dp[len1 - 1][len2 - 1][0]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
