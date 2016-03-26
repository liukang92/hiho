#include <iostream>
#include <string.h> 
using namespace std;
#define rep(i, m) for(i = 0; i < m; i++)
int s[][12]={{-2,1},{-2,2},{-1,1},{-1,2},
		{0,1},{0,2},{1,1},{1,2},
		{2,1},{2,2},{1,0},{2,0}
},
t[][8] = {{1,1},{-1,1},{0,1},{1,0},
{-1,0},{1,-1},{0,-1},{-1,-1}
},
mat[205][205],mine[205][205],
x[8],y[8],xx[8],yy[8],
T,i,j,m,n,k,p,no,no1,ax,ay,f,f1;

int ok(int a, int b){
	if(a < 0 || a >= m || b < 0 || b >= n)
		return 3;
	if(mat[a][b] == -1)
		return 2;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    scanf("%d",&T);
	while(T--){
		memset(mine,0,sizeof(mine));
		scanf("%d %d",&m,&n);
		rep(i,m) rep(j,n) scanf("%d",&mat[i][j]);
		rep(i,m) rep(j,n){
			if(mat[i][j] == -1) continue;
			rep(k, 8) x[k] = i + t[k][0], y[k] = j + t[k][1];
			no = 0;
			rep(k, 8) if(ok(x[k], y[k]) == 2) x[no] = x[k], y[no++] = y[k];
			if(mat[i][j] == 0) rep(k, no) mine[x[k]][y[k]] = -1;
			else if(mat[i][j] == no) rep(k, no) mine[x[k]][y[k]] = 1;
			rep(p, 12){
				ax = i + s[p][0], ay = j + s[p][1];
				if(ok(ax, ay) != 1) continue;
				rep(k, 8) xx[k] = ax + t[k][0], yy[k] = ay + t[k][1];
				no1 = 0;
				rep(k, 8) if(ok(xx[k],yy[k]) == 2) xx[no1] = xx[k], yy[no1++] = yy[k];
				f = f1 = 1;
				rep(k, no) if(abs(x[k] - ax) > 1 || abs(y[k] - ay) > 1) f = 0;
				rep(k, no1) if(abs(xx[k] - i) > 1 || abs(yy[k] - j) > 1) f1 = 0;
				if(mat[ax][ay] - mat[i][j] == no1 - no){
					if(f) rep(k, no1) if(abs(xx[k] - i) > 1 || abs(yy[k] - j) > 1) mine[xx[k]][yy[k]] = 1;
					if(f1) rep(k, no) if(abs(x[k] - ax) > 1 || abs(y[k] - ay) > 1) mine[x[k]][y[k]] = 1;
				}
			}
		}
		no=no1=0;
		rep(i,m) rep(j,n) if(mat[i][j]==-1){
			if(mine[i][j]==-1) no++;
			else if(mine[i][j]==1) no1++;
			}
		cout<<no1<<' '<<no<<endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
