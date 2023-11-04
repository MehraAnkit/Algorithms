/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        int maxdia(TreeNode* node,int& maxi){
            if(node==NULL){
                return 0;
            }
            int lh=maxdia(node->left, maxi);
            int rh=maxdia(node->right, maxi);
            maxi=max(maxi, lh+rh);
            return max(lh, rh)+1;
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        maxdia(root, maxi);
        return maxi;
    }
};
