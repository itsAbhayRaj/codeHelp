/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
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
    
***********************************************************/
void count(BinaryTreeNode<int> *root, int& c){
    if(root==NULL){
        return;
    }
    count(root->left,c);
    if(root->left==NULL & root->right==NULL)
    c++;
    count(root->right,c);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int c =0;
    count(root, c);
    return c;
    
}

// can also be done using other order traversals