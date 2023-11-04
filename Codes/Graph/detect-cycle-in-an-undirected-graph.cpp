//DFS CODE
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int src,int parent, vector<int> adj[], vector<int> &vis){
        vis[src]=1;
        for(auto ele: adj[src]){
            if(vis[ele]==0){
                if(dfs(ele,src, adj, vis)==true) return true;
            }else{
                if(ele!=parent){
                    return true;
                }
            }
        }
        return false;
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,-1, adj, vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}



// BFS CODE




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool bfs(int src, vector<int> adj[], vector<int> &vis, queue<pair<int, int>> &q){
        vis[src]=1;
        q.push({src,-1});
        
        while(!q.empty()){
            pair<int, int> p=q.front();
            q.pop();
            for(auto ele: adj[p.first]){
                if(vis[ele]==0){
                    q.push({ele, p.first});
                    vis[ele]=1;
                }else{
                    if(ele!=p.second){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V, 0);
        queue<pair<int, int>> q;
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(i, adj, vis, q)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
