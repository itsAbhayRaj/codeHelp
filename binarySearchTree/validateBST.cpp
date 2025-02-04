#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool checkBST(BinaryTreeNode<int> *root,int min ,int max){
    if(root==NULL) return true;
    if(root->data >= min && root->data <= max){
        bool left  = checkBST(root->left,min,root->data);
        bool right = checkBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return checkBST(root,INT_MIN,INT_MAX);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, vector<int> &res){
        if(root==NULL){
            return;
        }
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        solve(root,inOrder);
        for(int i =0;i<inOrder.size()-1;i++){
            if(inOrder[i]>=inOrder[i+1]){
                return false;
            }
        }
        return true;
    }
};

