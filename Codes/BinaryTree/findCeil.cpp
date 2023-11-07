int findCeil(struct Node* root, int x) {
    // your code here
    int sol=-1;
    while(root){
        if(root->data==x){
            return x;
        }else if(root->data<x){
            root=root->right;
        }else{
            sol=root->data;
            root=root->left;
        }
    }
    return sol;
}
