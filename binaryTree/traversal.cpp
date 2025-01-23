#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" --> ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }    
    cout<<root->data<<" --> ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    
    postOrderTraversal(root->right);
    cout<<root->data<<" --> ";
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 9 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);cout<<endl;
    cout<<"\nInorderTraversal"<<endl;
    inOrderTraversal(root);// 4 2 5 1 9 3
    cout<<"\nPreorderTraversal"<<endl;
    preOrderTraversal(root);// 1 2 4 5 3 9
    cout<<"\nPostorderTraversal"<<endl;
    postOrderTraversal(root);// 4 5 2 9 3 1
    return 0;
}