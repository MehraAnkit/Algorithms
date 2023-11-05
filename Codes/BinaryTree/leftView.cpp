/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
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
               
               if(cur->left) q.push(cur->left);
               if(cur->right) q.push(cur->right);
               
           }
       }
       return sol;
}
