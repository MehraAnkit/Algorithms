bool search(Node* root, int x) {
    // Your code here
    if(!root){
        return 0;
    }
    Node* temp=root;
    while(temp){
            if(temp->data==x){
            return 1;
        }else if(temp->data>x){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return 0;
    
}
