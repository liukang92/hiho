#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
const int M = 5005;
int n, m, total;
int res[M];

struct Vertex
{
    int head, in, out;
}v[N];

struct Edge
{
    int next, to, pair, state;
    Edge(){}
    Edge(int to, int next, int pair):to(to), next(next), pair(pair), state(0){}
}e[M * 2];

void init()
{
    total = 0;
    memset(v, 0, N * sizeof(Vertex));
    memset(e, 0, M * sizeof(Edge));
}

void conn(int a, int b, int p)
{
    e[++total] = Edge(b, v[a].head, total + p);
    v[a].head = total;
}

void scan()
{
    for (int i = 1; i <= n; i++)
    {
        for (int a = v[i].head; a; a = e[a].next)
        {
            v[i].out++;
            v[e[a].to].in++;
        }
    }
}

void dfs(int i)
{
	//res[++total] = i;//��ջ˳�� 
    while (v[i].out)
    {
        int a;
        for (a = v[i].head; a; a = e[a].next)
        {
            if (!e[a].state)
            {
                e[a].state = 1;
                v[i].out--;
                e[e[a].pair].state = 1;
                v[e[a].to].out--;
                break;
            }
        }
        dfs(e[a].to);
    }
    res[++total] = i;//��ջ˳�� 
}

void fleury()
{
    int start = 1;
    scan();
    for (int i = 1; i <= n; i++)
    {
        if (v[i].in % 2)
        {
            start = i;
            break;
        }
    }
    total = 0;
    dfs(start);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int a, b;
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        conn(a, b, 1);
        conn(b, a, -1);
    }
    fleury();
    printf("%d", res[1]);
    for (int i = 2; i <= total; i++)
    {
        printf(" %d", res[i]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
//	fclose(stdout);
#endif
}
