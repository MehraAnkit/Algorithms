// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> st;
        Node* cur=node;
        vector<int> sol;
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }else{
                Node* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    sol.push_back(temp->data);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        sol.push_back(temp->data);
                    }
                }else{
                    cur=temp;
                }
            }
        }
        return sol;
    }
};
