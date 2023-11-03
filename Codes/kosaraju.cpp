class Solution
{
    private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> adj2[], vector<int> &vis){
        vis[node]=1;
        for(auto it: adj2[node]){
            if(!vis[it]){
                dfs2(it, adj2, vis);
            }
        }
    }
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        //reversing the edges
        vector<int> adj2[V];
        for(int i=0;i<adj.size();i++){
            vis[i]=0;
            for(auto it: adj[i]){
                adj2[it].push_back(i);
            }
        }
        
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                dfs2(node, adj2, vis);
                cnt++;
            }
        }
        return cnt;
    }
};
