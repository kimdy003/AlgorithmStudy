#include <iostream>
#include <cstring>
using namespace std;

//���ĺ� ��
const int MAX = 26;

// ����ü�� ����� ������ ����ü�� 
// default�� public�̱� ����
struct TRIE
{
    //�� ���� ���ĺ��� ���� trie ��� ����
    TRIE *Node[MAX];
    bool Finish;

    //������
    TRIE() : Finish(false) {
    #if 1
        for(int i=0; i<MAX; i++){
            Node[i] = NULL;
        }
    #else
        memset(Node, NULL, sizeof(Node));
    #endif
    }

    //�Ҹ���
    ~TRIE(){
        for(int i=0; i<MAX; i++){
            if(Node[i])
                delete Node[i];
        }
    }

    void INSERT(const char *Str){
        if(*Str == '\0'){
            Finish = true;
            return;
        }

        int Cur = *Str - 'A';
        if(Node[Cur] == NULL)
            Node[Cur] = new TRIE();
        Node[Cur]->INSERT(Str+1);
    }

    //������ Ȯ��
    bool CALL(const char *Str){
        if(*Str == '\0')
            return true;

        if(Finish == true)
            return false;
        
        int Cur = *Str - 'A';
        return Node[Cur]->CALL(Str+1);
    }

    //�ش� ���ξ ������ �κ��� ��ġ�� ��ȯ
    TRIE *FIND(const char *Str){
        if(*Str == '\0')
            return this;

        int Cur = *Str - 'A';
        if(Node[Cur] == NULL){
            return NULL;
        }

        return Node[Cur]->FIND(Str+1);
    }
};

int main(){
#if 0
    //eof�� ���ö����� ��� �ޱ�
    while(1){
        string s;
        getline(cin, s, '\n');
        if(cin.eof() == true) break;
    }
#else
    TRIE *root = new TRIE();

    const char *words[5] = {"be", "bee", "can", "cat", "cd"};

    for(int i=0; i<5; i++){
        root->INSERT(words[i]);
    }

    root->CALL("be");
    root->FIND("bd");

    delete root;
#endif
}
