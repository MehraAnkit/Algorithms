Node* findlRight(Node* root){
    if(!root->right){
        return root;
    }
    return findlRight(root->right);
}

Node* solve(Node* root){
    if(!root->left){
        return root->right;
    }else if(!root->right){
        return root->left;
    }
    Node* rchild=root->right;
    Node* lRight=findlRight(root->left);
    lRight->right=rchild;
    return root->left;
}


Node *deleteNode(Node *root, int x) {
    // your code goes here
    if(!root){
        return NULL;
    }
    if(root->data==x){
        return solve(root);
    }
    Node* temp=root;
    while(temp){
        if(temp->data>x){
            if(temp->left && temp->left->data==x){
                temp->left=solve(temp->left);
                break;
            }else{
                temp=temp->left;
            }
        }else{
            if(temp->right && temp->right->data==x){
                temp->right=solve(temp->right);
                break;
            }else{
                temp=temp->right;
            }
        }
    }
    return root;
    
}
