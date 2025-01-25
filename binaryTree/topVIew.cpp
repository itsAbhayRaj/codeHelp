class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
       vector<int>ans;
       map<int,int> nodes;
       queue<pair<Node* ,int>>q;
       q.push(make_pair(root,0));
       while(!q.empty()){
           pair<Node*,int> temp = q.front();
           q.pop();
           Node* frontNode = temp.first;
           int hd = temp.second;
           if(nodes.find(hd)==nodes.end())
           nodes[hd]=frontNode->data;
           if(frontNode->left){
               q.push(make_pair(frontNode->left,hd-1));
           }
           if(frontNode->right)
           q.push(make_pair(frontNode->right,hd+1));
       }
       for(auto i:nodes){
           ans.push_back(i.second);
       }
       return ans;
    }
};