/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> sol;
       if(!root) return sol;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
               Node* cur=q.front();
               q.pop();
               if(i==0) sol.push_back(cur->data);
               
               if(cur->right) q.push(cur->right);
               if(cur->left) q.push(cur->left);
           }
       }
       return sol;
    }
};
