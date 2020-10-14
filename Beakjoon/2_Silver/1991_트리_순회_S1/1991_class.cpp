#include <iostream>

using namespace std;

class Tree{
    string data;
    Tree *left, *right;

public:
    Tree(){
        data = "";
        left = NULL;
        right = NULL;
    }

    void SetData(char data){
        this->data = data;
    }

    void SetLeft(Tree *left){
        this->left = left;
    }

    void SetRight(Tree *right){
        this->right = right;
    }

    void static preorder(Tree *root){
        if(root){
            cout << root->data;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void static inorder(Tree *root){
        if(root){
            inorder(root->left);
            cout << root->data;
            inorder(root->right);
    }
        }

    void static postorder(Tree *root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data;
        }
    }
};

int main(){
    int N;
    cin >> N;

    Tree *tree = new Tree[N];
    for(int i=0; i<N; i++){
        char data, left, right;
        cin >> data >> left >> right;

        tree[(int)(data-'A')].SetData(data);

        if(left != '.')
            tree[(int)(data-'A')].SetLeft(&tree[(int)(left-'A')]);
        else
            tree[(int)(data-'A')].SetLeft(NULL);

        if(right != '.')
            tree[(int)(data-'A')].SetRight(&tree[(int)(right-'A')]);
        else
            tree[(int)(data-'A')].SetRight(NULL);    
    }

    Tree *root = &tree[0];
    Tree::preorder(root);
    cout << "\n";
    
    Tree::inorder(root);
    cout << "\n";

    Tree::postorder(root);
    cout << "\n";
}