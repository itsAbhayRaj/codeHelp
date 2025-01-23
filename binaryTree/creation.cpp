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

void reverselevelOrderTraversal(Node* root){
    queue<Node*>q;
    stack<int>s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop();
        if(temp==NULL){
            s.push(-1);
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            s.push(temp->data);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        }
        
        
    }
    while(!s.empty()){
        if(s.top()==-1){
cout<<endl;
        }else{
                    cout<<s.top()<<" ";

        }
        s.pop();
    }
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 9 -1 -1 -1
    Node *root = NULL;
    root = buildTree(root);cout<<endl;
    levelOrderTraversal(root);
    reverselevelOrderTraversal(root);
    return 0;
}