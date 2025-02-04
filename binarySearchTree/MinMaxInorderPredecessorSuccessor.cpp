#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildBST(Node *root, int data)
{
    if (root == NULL)
    {

        root = new Node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = buildBST(root->left, data);
    }
    else
    {
        root->right = buildBST(root->right, data);
    }
    return root;
}
int minVal(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}
int maxVal(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int data)
{// this is using inOrder traversal sorted array by product
    if (!root)
        return;

    findPreSuc(root->left, pre, suc, data);

    if (root->data > data)
    {// first greater element
        if (!suc || (suc && suc->data > root->data))
            suc = root;
    }
    else if (root->data < data)
    {
        pre = root;
    }
    findPreSuc(root->right, pre, suc, data);
}
int predecessor(Node *root, int data)
{

    Node *pre = NULL;
    Node *suc = NULL;
    findPreSuc(root, pre, suc, data);
    return pre->data;
}
int successor(Node *root, int data)
{
    Node *pre = NULL;
    Node *suc = NULL;
    findPreSuc(root, pre, suc, data);
    return suc->data;
}
Node* rightMost(Node* root){
    Node* curr = root;
    while (curr->right)
    {
        curr = curr->right;
    }
    return curr;
    
}
Node* leftMost(Node* root){
    Node* curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
    
}
void findPreSucBST(Node* root,Node* &pre,Node* &suc,int data){
    Node* curr = root;
    while(curr){
        if(curr->data<data){
            pre = curr;
            curr = curr->right;
        }else if(curr->data>data){
            suc = curr;
            curr= curr->left;
        }else{
            if(curr->right){
                suc = leftMost(curr->right);
            }
            if(curr->left){
                pre = rightMost(curr->left);
            }
            break;
        }
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node *root = NULL;
    vector<int> data = {11, 7, 15, 5, 9, -1, 17, 2,8,10, 66, 18};
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] != -1)
            root = buildBST(root, data[i]);
    }
    cout << "\nLevel Order Traversal of Binary Search Tree is: \n";
    levelOrderTraversal(root);
    cout << "\nMin Value" << endl;
    cout << minVal(root) << endl;
    cout << "\nMax Value\n";
    cout << maxVal(root) << endl;
    int val = 9;
    // cout << "\nPredecessor Of " << val << endl;
    // cout << predecessor(root, val) << endl;
    // cout << "\nSuccessor Of " << val << endl;
    // cout << successor(root, val) << endl;
    Node* pre = NULL;
    Node* suc = NULL;
    findPreSucBST(root,pre,suc,val);
    cout << "\nPredecessor Of " << val << endl;
    cout <<pre->data << endl;
    cout << "\nSuccessor Of " << val << endl;
    cout << suc->data << endl;
    return 0;
}