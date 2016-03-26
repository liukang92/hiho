#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

struct TrieNode {
	char ch;
	TrieNode *child, *brother, *parent, *next;
	bool isStr;
	TrieNode(char c) : ch(c), child(NULL), brother(NULL), parent(NULL), next(NULL), isStr(0) {}
} *root = new TrieNode(0);

void insert(string str) {
	int len = str.length();
	TrieNode *p = root;
	for(int i = 0; i < len; ++i) {
		TrieNode *pc = p->child;
		while(pc != NULL && pc->ch != str[i]){
			pc = pc->brother;
		}
		if(pc == NULL) {
			TrieNode *t = new TrieNode(str[i]);
			t->brother = p->child;
			p->child = t;
			t->parent = p;
			p = t;
		} else{
			p = pc;
		}
	}
	p->isStr = 1;
}

TrieNode *getNode(TrieNode *r, char ch) {
	for(TrieNode *t = r->child; t; t = t->brother) {
		if(t->ch == ch){
			return t;
		}
	}
	return NULL;
}

void bfs() {
	queue<TrieNode *> myqueue;
	myqueue.push(root);
	while(!myqueue.empty()) {
		TrieNode *t = myqueue.front();
		myqueue.pop();
		for(TrieNode *tmp = t; tmp; tmp = tmp->brother) {
			if(tmp == root){
				tmp->next = NULL;
			}else if(tmp->parent == root){
				tmp->next = root;
			}else {
				TrieNode *tParent = tmp->parent->next;
				TrieNode *node;
				while(tParent != NULL && (node = getNode(tParent, tmp->ch)) == NULL){
					tParent = tParent->next;
				}
				if(tParent == NULL){
					tmp->next = NULL;
				}else{
					tmp->next = node;
				}
			}
		}
		if(t->child){
			myqueue.push(t->child);
		}
	}
}

bool find(string str) {
	TrieNode *t = root;
	int len = str.length();
	for(int i = 0; i < len; ++i) {
		TrieNode *node;
		while(t != NULL && (node = getNode(t, str[i])) == NULL){
			t = t->next;
		}
		if(t == NULL){
			t = root;
		}
		else{
			t = node;
		}
		if(t->isStr){
			return 1;
		}
	}
	return 0;
}

void show(TrieNode *node){
	queue<TrieNode *> myqueue;
	myqueue.push(root);
	myqueue.push(new TrieNode('#'));
	while(!myqueue.empty()) {
		TrieNode *t = myqueue.front();
		myqueue.pop();
		if(t->ch == '#'){
			if(!myqueue.empty()){
				myqueue.push(new TrieNode('#'));
			}
			cout<<endl;
			continue;
		}
		cout<<t->ch;
		t = t->child;
		while(t){
			myqueue.push(t);
			t = t->brother;
		}
	}
} 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	while(n--) {
		string str;
		cin >> str;
		insert(str);
	}
//	show(root);
	bfs();
	string str;
	cin >> str;
	printf("%s\n", find(str) ? "YES" : "NO");
	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
}
