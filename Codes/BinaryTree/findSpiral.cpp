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


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    bool ltr=true;
    vector<int> sol;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            Node* cur=q.front();
            q.pop();
            temp.push_back(cur->data);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            
        }
        if(ltr){
            reverse(temp.begin(), temp.end());
        }
        for(int i=0;i<n;i++){
            sol.push_back(temp[i]);
        }
        ltr=!ltr;
    }
    return sol;
}
