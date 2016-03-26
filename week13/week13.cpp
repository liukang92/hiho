#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, string> father;
map<string, bool> reach;

string update(string s){
	if (reach.find(s) != reach.end()){
		return s;
	}
	reach.insert(pair<string, bool>(s, true));
	if (father.find(s) == father.end())
		return "-1";
	return update(father[s]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n;
	string f, s;
	for (int i = 0; i < n; ++i){
		cin >> f >> s;
		father.insert(pair<string, string>(s, f));
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		cin >> f >> s;
		reach.clear();
		update(f);
		cout << update(s) << endl;
	}
	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
