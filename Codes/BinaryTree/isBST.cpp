class Solution
{
    public:
    bool isValid(Node* root, int mini, int maxi){
        if(!root){
            return true;
        }
        if(root->data<=mini || root->data>=maxi){
            return false;
        }
        return isValid(root->left, mini, root->data) && isValid(root->right, root->data, maxi);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return isValid(root, -1*INT_MIN, INT_MAX);
    }
};
