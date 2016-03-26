#include <iostream>
using namespace std;

const int branchNum = 26; //声明常量 
int i;

struct Trie_node{
    int count; //记录此字符串重复次数。
    int sufNum; //记录此节点下的字符串数 
    Trie_node *next[branchNum];//指向各个子树的指针,下标0-25代表26字符
    Trie_node():count(0), sufNum(0){
        for(int i = 0; i < branchNum; i++){
        	next[i] = NULL;
        }
    }
};

class Trie{
public:
    Trie();
    void insert(const char* word);
    int findPrefix(const char* word);
    bool search(const char* word); 
    void deleteTrie(Trie_node *root);
private:
    Trie_node* root;
};

Trie::Trie(){
    root = new Trie_node();
}

void Trie::insert(const char* word){
    Trie_node *location = root;
    while(*word){
        if(location->next[*word-'a'] == NULL){//不存在则建立
            Trie_node *tmp = new Trie_node();
            location->next[*word-'a'] = tmp;
        }
        location->sufNum++;
        location = location->next[*word-'a']; //每插入一步，相当于有一个新串经过，指针要向下移动
        word++;
    }
    location->count++; //到达尾部,增加一次重复标记
}

int Trie::findPrefix(const char *word){
    Trie_node *location = root;
    while(*word){
    	location = location->next[*word-'a'];
		word++;
		if(!location){ //子节点不存在则返回0 
    		return 0;
    	}
    }
   	return location->sufNum + location->count; //返回子字符串数+本身重复数 
}

bool Trie::search(const char *word){
    Trie_node *location = root;
    while(*word && location){
        location = location->next[*word-'a'];
        word++;
    }
    return(location!=NULL && location->count);
}

void Trie::deleteTrie(Trie_node *root){
    for(i = 0; i < branchNum; i++){
        if(root->next[i] != NULL){
            deleteTrie(root->next[i]);
        }
    }
    delete root;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
    char s[15];
    Trie t;
    cin >> n;
    while (n--){
        scanf("%s", s);
        t.insert(s);
    }
    cin >> n;
    while (n--){
        scanf("%s", s);
        printf("%d\n", t.findPrefix(s));
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
//	fclose(stdout);
#endif
    return 0;
}
