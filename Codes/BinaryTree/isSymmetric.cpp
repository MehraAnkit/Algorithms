/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    private:
    bool isSame(struct Node* left, struct Node* right){
        if(left==NULL || right==NULL){
            return (left==right);
        }
        if(left->data!=right->data){
            return false;
        }
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root){
	        return true;
	    }
	    return isSame(root->left, root->right);
    }
};
