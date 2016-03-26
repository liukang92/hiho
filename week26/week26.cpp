#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int const N = 1005, INF = 0x7FFFFFFF;
typedef pair<int, int> pii;
int n, dis[N][N], isIn[N], total;

void prim() {
    priority_queue<pii> que;
    int s, d;
	que.push(pii(dis[1][1], 1));
    while (!que.empty()){
        s = que.top().second;
		d = -que.top().first;
		que.pop();
		if(isIn[s]){
			continue;
		}
		isIn[s] = 1;
		total += d;
        for (int i = 1; i <= n; i++){
        	if (s != i && !isIn[i]){
            	que.push(pii(-dis[s][i], i));
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
	        scanf("%d", &dis[i][j]);
    	}
    }
    prim();
    cout << total << endl;
    return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
