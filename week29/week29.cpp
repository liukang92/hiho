#include <cstdio>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
const int N = 100005;
const int M = 1000005;
const int INF = 0x7FFFFFFF;

pii heap[M << 2];
int n, m, head[N], isIn[N], hSize, eSize, vSize, total;

struct E{
	int to, next, value;
}e[M << 1];

void push(int s, int v) {
	int i;
    for(i = ++hSize; heap[i >> 1].second > v; i >>= 1) {
        heap[i] = heap[i >> 1];
    }
    heap[i] = pii(s, v);
}

pii pop() {
    int i, child;
    pii min, last;
    if(hSize == 0) {
        return pii(0, 0);
    }
    min = heap[1];
    last = heap[hSize--];

    for(i = 1; i << 1 <= hSize; i = child) {
        child = i << 1;
        // pick bigger child
        if(child < hSize && heap[child + 1].second < heap[child].second) {
            child++;
        }
        if(last.second > heap[child].second) {
            heap[i] = heap[child];
        } else {
            break;
        }
    }
    heap[i] = last;
    return min;
}

void add(int from, int to, int value){
	e[++eSize].to = to;
	e[eSize].value = value;
	e[eSize].next = head[from];
	head[from] = eSize;
}

void prim() {
	pii t;
	push(1, 0);
    while (vSize < n){
        t = pop();
		if(isIn[t.first]){
			continue;
		}
		isIn[t.first] = 1;
		vSize++;
		total += t.second;
        for (int i = head[t.first]; i; i = e[i].next){
        	if (!isIn[e[i].to]){
            	push(e[i].to, e[i].value);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    int from, to, value;
    for (int i = 1; i <= m; i++) {
    	scanf("%d %d %d", &from, &to, &value);
    	add(from, to, value);
    	add(to, from, value);
    }
    prim();
    printf("%d\n", total);
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
