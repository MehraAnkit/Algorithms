class Solution
{
    public:
        Node* insert(Node* root, int x) {
        
            // Your code goes here
            if(!root){
        return new Node(x);
    }
    Node* temp=root;
    Node* parent=NULL;
    Node* node=new Node(x);
    while(temp){
        parent = temp;
            if(temp->data==x){
            return root;
        }else if(temp->data>x){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    
    if(parent==NULL){
        return temp;
    }
    if(x > parent->data){
        parent->right = node;
    }else{
        parent->left = node;
    }
        return root;
    }
    

};
