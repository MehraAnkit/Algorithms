/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* root){
        return root && !root->left && !root->right;
    }
    void leftBound(Node* root,vector<int>&ans){
        Node* cur=root->left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
    }
    void rightBound(Node* root,vector<int>&ans){
       Node* cur=root->right;
       vector<int> temp;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    void addLeaf(Node* root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaf(root->left, ans);
        if(root->right) addLeaf(root->right, ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> sol;
        if(!isLeaf(root)) sol.push_back(root->data);
        
        leftBound(root,sol);
        addLeaf(root,sol);
        rightBound(root,sol);
        return sol;
    }
};
