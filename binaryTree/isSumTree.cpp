pair<bool,int> isSumTreeFast(Node* root){
     if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
     }
     if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
     }
    pair<bool,int> left = isSumTreeFast(root->left);
    pair<bool,int> right = isSumTreeFast(root->right);
    pair<bool,int> ans;
    ans.second = left.second + right.second;
    bool curr = ans.second==root->data;
    if(curr && left.first && right.first){
        ans.first = true;
        ans.second += ans.second;
    }else{
        ans.first = false;
    }
    return ans;
}