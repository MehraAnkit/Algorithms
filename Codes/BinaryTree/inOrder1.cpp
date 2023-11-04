//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> sol;
        stack<Node*> st;
        Node* cur=root;
        while(true){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }else{
                if(st.empty()){
                    break;
                }
                cur=st.top();
                st.pop();
                sol.push_back(cur->data);
                cur=cur->right;
            }
        }
        return sol;
    }
};
