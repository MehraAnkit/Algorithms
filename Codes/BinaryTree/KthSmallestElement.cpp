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

class Solution {
    private:
    vector<int> inorderTraversal(Node* root){
       vector<int> inorder;
       Node* cur=root;
       while(cur){
           if(cur->left==NULL){
               inorder.push_back(cur->data);
               cur=cur->right;
           }else{
               Node* prev=cur->left;
               while(prev->right && prev->right!=cur){
                   prev=prev->right;
               }
               if(prev->right==NULL){
                   prev->right=cur;
                   cur=cur->left;
               }else if(prev->right==cur){
                   prev->right=NULL;
                   inorder.push_back(cur->data);
                   cur=cur->right;
               }
           }
       }
       return inorder;
       
    }
    
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        vector<int> ans=inorderTraversal(root);
        if(k>ans.size()){
            return -1;
        }
        return ans[k-1];
    }
};
