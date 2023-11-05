class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> sol;
        queue<pair<Node*, int>>q;
        map<int,int>mp;
        if(root==NULL){
            return sol;
        }
        q.push({root, 0});
        
        while(!q.empty()){
            Node* cur=q.front().first;
            int v=q.front().second;
            q.pop();
            mp[v]=cur->data;
            if(cur->left){
                q.push({cur->left, v-1});
            }
            if(cur->right){
                q.push({cur->right, v+1});
            }
        }
        for(auto it: mp){
            sol.push_back(it.second);
        }
        return sol;
    }
};
