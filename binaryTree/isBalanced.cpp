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
    cout << " enter data ";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new Node(data);
    cout << "\nLeft Child of " << data;
    root->left = buildTree(root->left);
    cout << "\nRight Child of " << data;
    root->right = buildTree(root->right);
    return root;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

// bool isBalanced(Node *root){ // naive approach O(n*2) height called and balanced call two function calls
// if(root==NULL){
//     return true;
// }
// bool left = isBalanced(root->left);
// bool right = isBalanced(root->right);
// bool diff = abs(height(root->left)-height(root->right))<=1;
// if(diff && left && right){
//     return true;
// }else{
//     return false;
// }
pair<bool,int> ifBalanced(Node* root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = ifBalanced(root->left);
    pair<bool,int> right = ifBalanced(root->right);
    bool diff = abs(left.second - right.second)<=1;
    pair<bool,int> ans;
    if(left.first && right.first && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    ans.second = max(left.second,left.second)+1;
    return ans;
}
bool isBalanced(Node* root){
return ifBalanced(root).first;
}

int main()
{
    // 10 20 40 -1 -1 60 -1 -1 30 -1 -1
    Node *root = NULL;
    root = buildTree(root);cout<<endl;
    cout<<isBalanced(root);
    return 0;
}