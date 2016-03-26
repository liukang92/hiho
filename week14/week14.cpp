#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> H;
int r[100005], c;
int f(int i){
	return r[i] == i ? i : r[i] = f(r[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m, A, B;
	string a,b;
	cin >> n;
	while(n--){
        cin >> m >> a >> b;
        if(!(A = H[a])){
        	A = H[a] = ++c;
			r[c] = c;
        }
        if(!(B = H[b])){
        	B = H[b] = ++c;
			r[c] = c;
		}
        if(m){
        	puts(f(A) == f(B) ? "yes" : "no");
		}
        else{
        	r[f(A)] = f(B);
		}
    }
    return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
