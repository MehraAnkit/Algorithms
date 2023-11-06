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
public:
    #define ll long long
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int sol=0;
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                TreeNode* cur=q.front().first;
                int idx=q.front().second-mini;
                q.pop();
                if(i==0)first=idx;
                if(i==n-1)last=idx;

                if(cur->left){
                    q.push({cur->left, (ll) 2*idx+1});
                }
                if(cur->right){
                    q.push({cur->right, (ll) 2*idx+2});
                }
            }
            sol=max(sol, last-first+1);
        }
        return sol;
    }
};
