class Solution {
    int visTime=1;
    private:
    void dfs(int node, vector<int> &vis,int parent, vector<int> adj[], int low[], int tim[], vector<int> &mark){
        vis[node]=1;
        tim[node]=low[node]=visTime;
        visTime++;
        int child=0;
        for(auto it: adj[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                dfs(it, vis,node, adj, low, tim, mark);
                low[node]=min(low[node], low[it]);
                
                if(low[it] >= tim[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }else{
                low[node]= min(low[node], tim[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int tim[V];
        int low[V];
        vector<int> mark(V, 0);
        vector<int> vis(V, 0);
        vector<int> sol;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis,-1, adj, low, tim, mark);
            }
        }
        for(int i=0;i<V;i++){
            if(mark[i]==1)
            sol.push_back(i);
        }
        if(sol.size()==0) return {-1};
        return sol;
    }
};
