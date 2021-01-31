#include <iostream>
#include <cstring>
using namespace std;

//알파벳 수
const int MAX = 26;

// 구조체를 만드는 이유는 구조체의 
// default가 public이기 때문
struct TRIE
{
    //각 영어 알파벳에 대한 trie 노드 생성
    TRIE *Node[MAX];
    bool Finish;

    //생성자
    TRIE() : Finish(false) {
    #if 1
        for(int i=0; i<MAX; i++){
            Node[i] = NULL;
        }
    #else
        memset(Node, NULL, sizeof(Node));
    #endif
    }

    //소멸자
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

    //마지막 확인
    bool CALL(const char *Str){
        if(*Str == '\0')
            return true;

        if(Finish == true)
            return false;
        
        int Cur = *Str - 'A';
        return Node[Cur]->CALL(Str+1);
    }

    //해당 접두어가 끝나는 부분의 위치를 반환
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
    //eof가 나올때까지 계속 받기
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
