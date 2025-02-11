#include <bits/stdc++.h> 
struct node{
    int val;
    int row;
    int col;
    node(int data,int i,int j){
        this->val = data;
        this->row = i;
        this->col = j;
    }
};
class compare{
    public:
bool operator()  (node* a,node* b){
    return a->val > b->val;
}
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node* , vector<node*> , compare> pq;  
     vector<int> result;
     for(int i =0;i<k;i++){
         node* tmp = new node(kArrays[i][0],i,0);
         pq.push(tmp);
     }
     while(!pq.empty()){
         node* tmp = pq.top();
         result.push_back(tmp->val);
         pq.pop();
         if(tmp->col+1 < kArrays[tmp->row].size()){
             node* next = new node(kArrays[tmp->row][tmp->col+1],tmp->row,tmp->col+1);
             pq.push(next);
         }
     }
     return result;
}
