#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
void buildBST(Node* &root,int data){
    if(root==NULL){
        root =  new Node(data);
        return;
    }
    if(data < root->data){
         buildBST(root->left,data);
    }
    else{
         buildBST(root->right,data);
    }

}
void inorderTraversal(Node* root,vector<int> &arr){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left,arr);
    arr.push_back(root->data);
    inorderTraversal(root->right,arr);
}
void convertToHeap(Node* &root,int &i,vector<int> &arr){
    if(root==nullptr) return;

    root->data = arr[i++];
    convertToHeap(root->left,i,arr);
    convertToHeap(root->right,i,arr);
}
int main(){
    vector<int> arr = {4,2,6,1,3,5,7};
    Node* root = NULL;
    for(int i =0;i<arr.size();i++){
        buildBST(root,arr[i]);
    }
    arr.clear();
    inorderTraversal(root,arr);
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    // arr.clear();
    int i =0;
    convertToHeap(root,i,arr);
    arr.clear();
    inorderTraversal(root,arr);
    for(int i: arr){
        cout<<i<<" ";
    }
}