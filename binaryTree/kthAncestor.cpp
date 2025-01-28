#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
int kthAncestor(Node *root, int k, int node);
int main()
{
    
		Node* root = buildTree("1 2 3 4 54 5");
		cout<<kthAncestor(root,k,node)<<endl;
    

}

/
Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k==0) 
        {
            //answer lock
            // k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k==0) 
        {
            //answer lock
            // k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}


/User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void solve(Node *root, int node,vector<int>& path,int k,int &ans){
  if (root == NULL || ans != -1) {
        return; // Stop recursion if the answer is found or root is NULL
    }

    path.push_back(root->data); // Add current node to the path

    if (root->data == node) { // Target node is found
        if (path.size() > k) {
            ans = path[path.size() - k - 1]; // Find k-th ancestor
        }
        path.pop_back(); // Backtrack
        return;
    }

    // Recurse for left and right subtrees
    solve(root->left, node, path, k, ans);
    solve(root->right, node, path, k, ans);

    path.pop_back(); 
    
}
int kthAncestor(Node *root, int k, int node)
{
   if (root == NULL) return -1; // Edge case: NULL tree

    vector<int> path; // To store the path from root to the target node
    int ans = -1;     // To store the result
    solve(root, node, path, k, ans);

    return ans;
}