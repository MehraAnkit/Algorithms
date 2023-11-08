/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class BSTIterator {
    stack<Node*> st;
    bool reverse;
public:
    BSTIterator(Node* root, bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        Node *topnode=st.top();
        st.pop();
        if(!reverse) pushAll(topnode->right);
        else pushAll(topnode->left);
        
        return topnode->data;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
private:
    void pushAll(Node* node){
        for(;node!=NULL;){
            st.push(node);
            if(reverse){
                node=node->right;
            }else{
                node=node->left;
            }
        }
    }
};

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    if(!root){
        return 0;
    }
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i=l.next();
    int j=r.next();
    while(i<j){
        if(i+j==target) return true;
        else if(i+j<target) i=l.next();
        else
        j=r.next();
    }
    return 0;
    }
};
