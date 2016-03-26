#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define ERRSTR printf("Incorrect performance log\n"); return 0;

struct Func{
	string name;
	int startTime;
	int runTime;
}func;

int index;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n,hh,mm,ss,tt;
	char fun[256],act[256];
	scanf("%d",&n);
	stack<Func> stk;
	vector<Func> vec;
	map<string,int> ids;
	rep(i,n) {
		scanf("%s %d:%d:%d %s",fun,&hh,&mm,&ss,act);
		string sf = fun, sa = act;
		tt = hh * 3600 + mm * 60 + ss;
		if(sa == "START") {
			if(ids.count(sf)) {ERRSTR;}
			ids[sf] = index++;
			func.name = sf;
			func.startTime = tt;
			stk.push(func);
			vec.push_back(func);
		} else {
			if(stk.empty() || stk.top().name != sf) {
				ERRSTR;
			} else {
				stk.pop();
				int id = ids[sf];
				if(tt < vec[id].startTime) {ERRSTR;}
				vec[id].runTime = tt - vec[id].startTime;
			}
		}
	}
	if(!stk.empty()) {ERRSTR;}
	rep(i,vec.size()) {
		printf("%s %02d:%02d:%02d\n", vec[i].name.c_str(), vec[i].runTime / 3600, (vec[i].runTime % 3600) / 60, vec[i].runTime % 60);
	}
	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
	return 0;
}
