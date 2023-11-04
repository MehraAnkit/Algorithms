class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int src, vector<int> adj[], vector<int> &sol, vector<bool> &vis){
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int ele=q.front();
            sol.push_back(ele);
            q.pop();
            for(auto it: adj[ele]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        vector<int> sol;
        bfs(0, adj, sol, vis);
        return sol;
    }
};
