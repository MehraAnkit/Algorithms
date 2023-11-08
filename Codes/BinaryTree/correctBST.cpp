/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
    Node* first;
    Node* middle;
    Node* last;
    Node* prev;
    
    void inorder(Node* root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(prev!=NULL && (root->data < prev->data)){
            if(first==NULL){
                first=prev;
                middle=root;
            }else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        first=middle=last=NULL;
        prev=new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data, last->data);
        else if(first && middle) swap(first->data, middle->data);
    }
};
