#include <string.h>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 105;
const int M = 1005;

int tot = 0;
int dis[N][N];

void floyd(int n){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(k != i && k != j){
					dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
} 

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int nPoint, nRoad;
	scanf("%d %d", &nPoint, &nRoad);
	memset(dis, 0x3f, sizeof(dis));
	int from, to, val;
	for(int i = 1; i <= nRoad; i++){
		scanf("%d %d %d", &from, &to, &val);
		if(dis[from][to] > val){
			dis[from][to] = dis[to][from] = val;
		} 
	}
	floyd(nPoint);
	for(int i = 1; i <= nPoint; i++){
		dis[i][i] = 0;
		for(int j = 1; j <= nPoint; j++){
			printf("%d ",dis[i][j]);
		}
		printf("\n");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
