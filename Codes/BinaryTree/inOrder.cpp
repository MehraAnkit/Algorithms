/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
    private:
    void recurIn(Node *root, vector<int>& sol){
        if(root==NULL){
            return;
        }
        recurIn(root->left, sol);
        sol.push_back(root->data);
        recurIn(root->right, sol);
    }
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> sol;
        recurIn(root, sol);
        return sol;
    }
};
