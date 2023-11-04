class Solution {
    private:
        void dfs(int src, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis){
            vis[src]=1;
            for(auto ele: adj[src]){
                int ver=ele.first;
                if(vis[ver]==0){
                    dfs(ver, adj, st, vis);
                }
            }
            st.push(src);
        }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        
        vector<int> vis(N, 0);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
        }
        
        
        stack<int> s;
        dfs(0, adj, s, vis);
        
        
        vector<int> dist(N, INT_MAX);
        dist[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            
            for(auto it: adj[node]){
                if(dist[node]+ it.second< dist[it.first]){
                    dist[it.first]=dist[node]+ it.second;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};
