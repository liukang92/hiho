#include <cstdio>

const int N = 1000005;
int a[N], ret;

void find(int left, int right, int k){
	int mid = (left + right) >> 1;
	int val = a[mid];
	int tmp;
	int i = left, j = right;
	while(i < j){
		while(a[i] < val){
			i++;
		}
		while(a[j] > val){
			j--;
		}
		if(i != j){
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	if(i > k){
		find(left, i - 1, k);
	}else if(i < k){
		find(i + 1, right, k);
	}else{
		ret = val;
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
	int n, k;
    scanf("%d %d",&n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    find(1, n, k);
    printf("%d\n", ret);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}