#include <cstdio>

using namespace std;

const int N = 100005;
const int INF = 0x7FFFFFFF;
int hsize = 0, heap[N];

void add(int x) {
	int i;
    for(i = ++hsize; heap[i >> 1] < x; i >>= 1) {
        heap[i] = heap[i >> 1];
    }
    heap[i] = x;
}

int pop() {
    int max, last, i, child;
    if(hsize == 0) {
        return 0;
    }
    max = heap[1];
    last = heap[hsize--];

    for(i = 1; i << 1 <= hsize; i = child) {
        child = i << 1;
        // pick bigger child
        if(child < hsize && heap[child + 1] > heap[child]) {
            child++;
        }
        if(last < heap[child]) {
            heap[i] = heap[child];
        } else {
            break;
        }
    }
    heap[i] = last;
    return max;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
    char act;
    int weight;
    heap[0] = INF;
    scanf("%d", &n);
    while(n--) {
        act = getchar();
        while(act != 'A' && act != 'T'){
        	act = getchar();
		} 
        if(act == 'A') {
        	scanf("%d", &weight);
            add(weight);
        } else if(act == 'T') {
            printf("%d\n", pop());
        }
    }
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
