#include <cstdio>
int a,n,k,f,c;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(a<=k)++c;
        if(a==k)f=1;
    }
    if(!f)c=-1;
    printf("%d\n",c);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}