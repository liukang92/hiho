#include <cstdio>
using namespace std;
#define C(c) (c<='Z'?c-'A':c-'a'+26)
const int N=100100;
struct _E{
    int to,id,next;
}E[2][N<<1];
int G[2][N],e[2];
void conn(const int&i,const int&u,const int&v,const int&id=-1){
    E[i][++e[i]].to=v;
    E[i][e[i]].id=id;
    E[i][e[i]].next=G[i][u];
    G[i][u]=e[i];
}
int T[N][52],t,d[N],c;
char *m[N];
int H(char *ss){
    int p=0,v;
    for(char *s=ss;*s;++s){
        v=C(*s);
        if(!(T[p][v]))T[p][v]=++t;
        p=T[p][v];
    }
    if(d[p])return d[p];
    else{
        m[++c]=ss;
        return d[p]=c;
    }
}
char a[N][100],b[N][100];
int A,B,r[N],n,L[N];
int F(int i){return r[i]==i?i:r[i]=F(r[i]);}

void dfs(int u,int p){
    r[u]=u;
    int v;
    for(int i=G[0][u];i;i=E[0][i].next)if((v=E[0][i].to)!=p)dfs(v,u);
    for(int i=G[1][u];i;i=E[1][i].next)if(r[E[1][i].to])L[E[1][i].id]=F(E[1][i].to);
    r[u]=p;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s%s",a[i],b[i]);
        A=H(a[i]);B=H(b[i]);
        conn(0,A,B);conn(0,B,A);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s%s",a[0],b[0]);
        A=H(a[0]);B=H(b[0]);
        conn(1,A,B,i);conn(1,B,A,i);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i)puts(m[L[i]]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
