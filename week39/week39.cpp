#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100005;
typedef long long int64;

int n;
int a[N], b[N];

int64 merge(int l, int r){
	int64 cnt = 0;
	if(l < r){
		int mid = (l + r) >> 1;
		cnt = merge(l, mid) + merge(mid + 1, r);
		for(int i = l, left = l, right = mid + 1; i <= r; i++){
			if(right > r){
				b[i] = a[left++];
			}else if(left > mid){
				b[i] = a[right++];
			}else{
				if(a[left] <= a[right]){
					b[i] = a[left++];
				}else{
					b[i] = a[right++];
					cnt += (mid - left + 1);
				}
			}
		}
		memcpy(a + l, b + l, (sizeof(int)) * (r - l + 1));
	}
	return cnt; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif 
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%lld\n", merge(1, n));
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
