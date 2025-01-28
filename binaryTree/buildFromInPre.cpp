//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    private:
    void createMapping(vector<int>inorder,unordered_map<int,int> &you){
        for(int i=0;i<inorder.size();i++)
        {
                        you[inorder[i]] = i;
        }
    }
    Node* solve(vector<int> inorder,vector<int> preorder,int &index,
    int start,int end,int n,unordered_map<int,int>&nodeToIndex){
        if(index>=n || start>end)return nullptr;
        Node* root = new Node(preorder[index]);
        int pos = nodeToIndex[preorder[index++]];
        root->left = solve(inorder,preorder,index,start, pos- 1,n,nodeToIndex);
        root->right = solve(inorder,preorder,index,pos + 1,end,n,nodeToIndex);
        return root;
    }
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        unordered_map<int,int> nodeToIndex;
createMapping(inorder,nodeToIndex);
int index = 0;
        Node* root =solve(inorder,preorder,index,0,n-1,n,nodeToIndex);
        return root;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends