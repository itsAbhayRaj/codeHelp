#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
     int data;
     Node* left;
     Node* right;
     Node(int data)
     {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};


Node* buildBST(Node* root,int data)
{
    if(root==NULL)
    {
       
        root =  new Node(data);
        return root;
    }
    if(data < root->data)
    {
      root->left= buildBST(root->left,data);
    }
    else
    {
        root->right=  buildBST(root->right,data);
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
        {            cout << temp->data << " ";

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
    Node* root = NULL;
    vector<int> data = {10,7,15,5,9,-1,17,2,66,18};
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] != -1)
        root = buildBST(root,data[i]);
    }
    levelOrderTraversal(root);
    return 0;
}