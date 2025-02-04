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
Node* maxNode(Node*root){
    Node* curr = root;
    while(curr->right){
        curr = curr->right;
    }
    return curr;
}
Node* deleteFromBST(Node* root, int key) {
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        // delete
        // leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // one child Node
        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(root->right && !root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // both child
        if(root->left && root->right){
            int maxi = maxNode(root->left)->data;
            root->data = maxi;
            root->left = deleteFromBST(root->left,maxi);
        }
    }
    else if(root->data<key){
        root->right = deleteFromBST(root->right,key);
    }else if(root->data>key){
        root->left = deleteFromBST(root->left,key);
    }
    return root;
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
    deleteFromBST(root, 2);
    cout << "\nLevel Order Traversal of Binary Search Tree is: \n";
    levelOrderTraversal(root);
    return 0;
}