//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
void recurPost(Node *root, vector<int>& sol){
    if(root==NULL){
        return;
    }
    recurPost(root->left, sol);
    recurPost(root->right, sol);
    sol.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> sol;
  recurPost(root, sol);
  return sol;
}
