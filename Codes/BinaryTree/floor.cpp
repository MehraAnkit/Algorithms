class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
    int sol=-1;
    while(root){
        if(root->data==x){
            return x;
        }else if(root->data<x){
            sol=root->data;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return sol;
    }
};
