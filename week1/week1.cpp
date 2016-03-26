#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;

const int N = 1 << 23;
int p[N];

int findString(string s)
{
    string str = "$#";
    for (int i = 0; s[i]; i++)
    {
        str.append(1, s[i]);
        str.append("#");
    }
    cout<<str<<endl; 
    int max = 0;
    int res = 0;
    int id;
    for (int i = 1; str[i]; i++)
    {
        if (max > i)
        {
            p[i] = min(p[2 * id - i], max - i);//i不超过max时可以求其最小值，仅一种情况取大于
        }
        else
        {
            p[i] = 1;
        }
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++);//未进行分类讨论直接尝试匹配
	
        if (p[i] + i > max)
        {
            max = p[i] + i;
            id = i;
        }
        if (res < p[i])
        {
            res = p[i];
        }
    }
    cout<<" ";
    for (int i = 1; str[i]; i++)
    {
        cout<<p[i];
    }
    cout<<endl;
    return res - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        cout << findString(s) << endl;
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
