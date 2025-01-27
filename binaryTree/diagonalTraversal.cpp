class Solution {
    private:
    void solve(Node* root,map<int,vector<int>> &nodes,int lvl){
        if(root==NULL)return;
        nodes[lvl].push_back(root->data);
        solve(root->left,nodes,lvl+1);
        solve(root->right,nodes,lvl);
    }
  public:
    vector<int> diagonal(Node *root) {
       vector<int> ans;
       map<int,vector<int>> nodes;
       solve(root,nodes,0);
       for(auto I:nodes){
           for(int j:I.second)
           ans.push_back(j);
       }
       return ans;
    }
};