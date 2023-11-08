/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxsize;
    int minval;
    int maxval;
    
    NodeValue(int minNode, int maxNode, int size){
        this->minval=minNode;
        this->maxval=maxNode;
        this->maxsize=size;
    }
    
};

class Solution{
    private:
    NodeValue postorder(Node* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left=postorder(root->left);
        auto right=postorder(root->right);
        
        if(left.maxval<root->data && root->data< right.minval){
            return NodeValue(min(root->data, left.minval), max(root->data, right.maxval), 
            left.maxsize+right.maxsize+1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return postorder(root).maxsize;
    }
};
