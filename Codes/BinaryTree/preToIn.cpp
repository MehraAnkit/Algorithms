class Solution {
    private:
    TreeNode* tree(map<int,int>& mp,vector<int>& in,int ins, int ine, vector<int>& pre,int pres, int pree){
        if(pres>pree || ins>ine){
            return NULL;
        }
        TreeNode* root= new TreeNode(pre[pres]);
        int inroot= mp[root->val];
        int numleft=inroot-ins;
        
        root->left=tree(mp,in,ins, inroot-1,pre,pres+1, pres+numleft);
        root->right=tree(mp,in,inroot+1,ine,pre,pres+numleft+1,pree);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root= tree(mp,inorder,0, inorder.size()-1, preorder,0, preorder.size()-1);
        
        return root;
    }
};
