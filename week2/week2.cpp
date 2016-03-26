#include <iostream>
using namespace std;

const int branchNum = 26; //�������� 
int i;

struct Trie_node{
    int count; //��¼���ַ����ظ�������
    int sufNum; //��¼�˽ڵ��µ��ַ����� 
    Trie_node *next[branchNum];//ָ�����������ָ��,�±�0-25����26�ַ�
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
        if(location->next[*word-'a'] == NULL){//����������
            Trie_node *tmp = new Trie_node();
            location->next[*word-'a'] = tmp;
        }
        location->sufNum++;
        location = location->next[*word-'a']; //ÿ����һ�����൱����һ���´�������ָ��Ҫ�����ƶ�
        word++;
    }
    location->count++; //����β��,����һ���ظ����
}

int Trie::findPrefix(const char *word){
    Trie_node *location = root;
    while(*word){
    	location = location->next[*word-'a'];
		word++;
		if(!location){ //�ӽڵ㲻�����򷵻�0 
    		return 0;
    	}
    }
   	return location->sufNum + location->count; //�������ַ�����+�����ظ��� 
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
