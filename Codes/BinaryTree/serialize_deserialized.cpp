class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
        vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        
        if(root == NULL) return ans; 
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node == NULL)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(node->data);
            }
            if(node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
   Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int index = 0;
       if(A.size() == index) return NULL;
       
       int value = A[index++];
       if(value == -1) return NULL;
       
       Node* root = new Node(value);
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty())
       {
           Node* node = q.front();
           q.pop();
           
           value = A[index++];
           if(value == -1)
           {
               node->left=NULL;
           }
           else
           {
               Node* temp1 = new Node(value);
               node->left = temp1;
               q.push(temp1);
           }
           
           value = A[index++];
           if(value == -1)
           {
               node->right = NULL;
           }
           else
           {
               Node* temp2 = new Node(value);
               node->right = temp2;
               q.push(temp2);
           }
       }
       return root;
    }

};
