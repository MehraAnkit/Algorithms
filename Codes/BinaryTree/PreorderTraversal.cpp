/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the preorder traversal of the tree.
void recurPre(Node *root, vector<int> &sol){
    if(root==NULL){
        return;
    }
    sol.push_back(root->data);
    recurPre(root->left, sol);
    recurPre(root->right, sol);
    
}
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> sol;
  recurPre(root, sol);
  return sol;
}