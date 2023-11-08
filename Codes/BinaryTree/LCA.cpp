class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(root==NULL){
           return NULL;
       }
       int cur=root->data;
       if(cur< n1 and cur<n2){
           return LCA(root->right, n1, n2);
       }
       if(cur> n1 and cur>n2){
           return LCA(root->left, n1, n2);
       }
       return root;
        }

};
