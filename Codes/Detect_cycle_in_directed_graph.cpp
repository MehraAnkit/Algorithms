//DFS CODE

class Solution {
    private:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
        vis[src]=1;
        pathVis[src]=1;
        for(auto ele: adj[src]){
            if(vis[ele]==0){
                if(dfs(ele,adj, vis,pathVis)==true){
                    return true;
                }
            }else if(pathVis[ele]==1){
                return true;
            }
        }
        pathVis[src]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0),pathVis(V, 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj, vis, pathVis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};


//BFS CODE

