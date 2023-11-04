class Solution {
    private:
    int maxSum(Node* root, int& maxi){
        if(!root){
            return 0;
        }
        int lsum=max(0,maxSum(root->left, maxi));
        int rsum=max(0, maxSum(root->right, maxi));
        maxi=max(maxi, lsum+rsum+root->data);
        return root->data + max(lsum, rsum);
    }
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int maxi=INT_MIN;
        maxSum(root, maxi);
        return maxi;
    }
};
