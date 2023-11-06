class Solution {
  public:
  int leftHeight(Node* root){
    int h=0;
    Node* cur=root;
    while(cur){
        cur=cur->left;
        h++;
    }
    return h;
}
int rightHeight(Node* root){
    int h=0;
    Node* cur=root;
    while(cur){
        cur=cur->right;
        h++;
    }
    return h;
}
    int countNodes(Node* root) {
        // Write your code here
        if(!root){
            return 0;
        }
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh) return (1<<lh)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};
