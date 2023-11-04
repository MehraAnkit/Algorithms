//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> sol;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curNode=st.top();
            st.pop();
            sol.push_back(curNode->data);
            
            if(curNode->right!=NULL){
                st.push(curNode->right);
            }
            if(curNode->left!=NULL){
                st.push(curNode->left);
            }
        }
        
        return sol;
    }
};
