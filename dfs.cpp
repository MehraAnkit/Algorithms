class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<int> adj[], vector<bool> &vis, vector<int> &sol){
        sol.push_back(src);
        vis[src]=true;
        for(auto it: adj[src]){
            if(!vis[it]){
                dfs(it, adj, vis, sol);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        vector<int> sol;
        dfs(0,adj,vis, sol);
        return sol;
    }
};
