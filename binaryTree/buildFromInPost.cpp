//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
    private:
    void createMapping(vector<int> in,map<int,int> &nodeToIndex)
    {
        for(int i =0;i<in.size();i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(vector<int> inorder,vector<int> postorder,int &index,int start,int end,int n,map<int,int> nodeToIndex)
    {
        if(index<0 || start > end)
        {
            return NULL;
        }
        Node* root = new Node(postorder[index]);
        int pos = nodeToIndex[postorder[index--]];
        
        root->right = solve(inorder,postorder,index,pos+1,end,n,nodeToIndex);
        root->left = solve(inorder,postorder,index,start,pos-1,n,nodeToIndex);
        return root;
    }
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex);
        // reverse(postorder.begin(),postorder.end());
        int index = inorder.size()-1;
        Node* root = solve(inorder,postorder,index,0,inorder.size()-1,inorder.size(),nodeToIndex);
        return root;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends