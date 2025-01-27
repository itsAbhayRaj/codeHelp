#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void solve(Node *root, int len, int &maxLen, int &sum, int &maxSum)
    {
        if (root == NULL){
           
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
                
            }else if(len==maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }
       
            sum += root->val;
            solve(root->left,len+1,maxLen,sum,maxSum);
            solve(root->right,len+1,maxLen,sum,maxSum);
        
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        return solve(root, len, maxLen, sum, maxSum);
    }
};