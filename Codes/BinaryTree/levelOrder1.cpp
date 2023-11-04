/* A binary tree Node

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


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
      q.push(node);
      vector<int> sol;
      while(!q.empty()){
          Node* cur=q.front();
          q.pop();
          sol.push_back(cur->data);
          if(cur->left!=NULL){
              q.push(cur->left);
          }
          if(cur->right!=NULL){
              q.push(cur->right);
          }
      }
      return sol;
    }
};
