#include <stdio.h>
#include <string.h>

int count = 0;
char s[10005],l[1000005];

void getNext(char *str, int *next){
	int len = strlen(str);
	int i = 0, j = -1;
	next[i] = j;
	while(i < len){
		while(j != -1 && str[j] != str[i]){
			j = next[j];
		}
		next[++i] = ++j;
	}
}

void kmp(char *s, char *l)
{
	int next[10005];
	int llen = strlen(l);
	int slen = strlen(s);
	getNext(s, next);
	int i = 0, j = 0;
	while(i < llen){
		while(j != -1 && s[j] != l[i]){
			j = next[j];
		}
		i++,j++;
		if(j == slen){
			count++;
			j = next[j];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int t;
	scanf("%d",&t);
	while (t--)
	{
		count=0;
		scanf("%s%s", &s, &l);
		kmp(s, l);
		printf("%d\n", count);
	}
	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
